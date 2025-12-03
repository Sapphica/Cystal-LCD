# Crystal-LCD

_A custom Rainmeter telemetry engine driving a 1920×480 glass LCD with real-time PC stats, overclock info, and FPS._

![Build](https://img.shields.io/badge/build-passing-8A2BE2?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?style=for-the-badge&logo=windows)
![Rainmeter](https://img.shields.io/badge/Rainmeter-Custom_Skin-ff69b4?style=for-the-badge)
![Lua](https://img.shields.io/badge/Lua-Scripting-2C2D72?style=for-the-badge&logo=lua&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-Plugin_Backend-00599C?style=for-the-badge&logo=c%2B%2B)
![HWiNFO](https://img.shields.io/badge/Telemetry-HWiNFO-00A4EF?style=for-the-badge)
![MSI Afterburner](https://img.shields.io/badge/FPS-MSI_Afterburner-006F3D?style=for-the-badge)

---

## Demo

<div align="center">
  <img src="https://github.com/Sapphica/Crystal-LCD/blob/main/assets/LCD.gif" alt="Crystal-LCD Telemetry Panel" width="720">
</div>

---

## Purpose

Crystal-LCD is a **glass-style telemetry HUD** for a dedicated 1920×480 LCD panel.  
It’s built to sit under the main display and show **everything that actually matters** while gaming or stress-testing:

- CPU clocks, temps, utilization, power, overclock indicator  
- GPU clocks, temps, VRAM usage, PCIe link speed, power draw  
- FPS (live + rolling average) with layout switching at high framerates  
- Pump RPM, radiator temperature (current + max)  
- Per-drive SMART health, lifespan, and temperature  
- System uptime, RAM usage, top CPU process

All of this is driven through **Rainmeter + HWiNFO + MSI Afterburner + plugins**, wired together by a single 'CrystalTelemetry.ini' and 'GIF.ini'.

---

## Notes

- **This skin is tuned for a specific hardware setup and resolution (1920×480).
- **It can be adapted, but the intent is very much:
- **“This is my personal glass telemetry cockpit.”

The .ini is intentionally dense: it’s a full subsystem, not a toy widget.

---

## Features

### CPU Telemetry

- **CPU total usage** (`measureCPU`) with warning color when > 90%  
- **Per-core utilization** (`measureCPUCore1` … `measureCPUCore8`)  
- **Active clock selection** via `ClockSelect`:
  - Picks the “real” active core / CCD based on utilization (e.g. 3D cache CCD vs non-3D)  
- **CPU clock reporting** (`CPU_CLOCK0`, `CPU_CLOCK1`)  
- **CPU voltage** (`CPU_VOLT0`)  
- **CPU package power** (`CPU_Power`, `CPU_PowerMax`)  
- **CPU temperature (current + max)** via `CPU_TEMP0` / `CPU_TEMP0M`  
- **Overclock indicator**:
  - `LetterSelect` + `Pulse` + `MeterOverclock`
  - Text: `Overclock: <clock> <label>`
  - Changes color when your x3D / OC path is active

### GPU Telemetry (GPU 0 + optional GPU 1)

- **Core clock** (`GPU_CORE_CLOCK0`, `GPU_CORE_CLOCK1`)  
- **Memory clock** (`GPU_MEM_CLOCK0`, `GPU_MEM_CLOCK1`)  
- **GPU temperature (current + max)** (`GPU_TEMP0`, `GPU_TEMP0M`, `GPU_TEMP1`)  
- **PCIe link speed** (`PCIe_LINK0`, `PCIe_LINK1`)  
- **GPU voltage** (`GPU_VOLT`)  
- **GPU total board power** (`GPU_TOTAL_PWR`, `GPU_TOTAL_PWRMax`)  
- **VRAM usage %** (`GPU_MEM_USAGE%`)  
- **VRAM allocated (human readable)** (`GPU_MEM_USED`, `GPU_MEM_USED1`)  

Rendered as:

- Big GPU temp readout: `GPU: <current>°C | <max>°C`  
- VRAM usage readout: GB/MB scaled text  
- PCIe + VRAM + GPU voltage line: `PCIe <GT/s>  <VRAM>  <Vcore>`

### FPS + Performance Behavior

Using **MSI Afterburner plugin**:

- `MeasureFPS` – live FPS  
- `MeasureFPSAvg` – smoothed rolling average  
- `MeasureFPSBoth100` – helper to check when both live and avg FPS ≥ 100

Layout behavior:

- **`MeterFPSBig`** shown when FPS < 100  
- **`MeterFPSSmall`** shown when FPS ≥ 100  
- Auto-switching handled by `IfCondition` on `MeasureFPSBoth100`  
- Display text: `FPS: <live>|<avg>`

A refresh hotspot (`MeterRefresh`) lets you click to force a skin refresh / FPS reset from the LCD.

### Memory + System

- **Physical RAM used vs total**:
  - `MeasurePhysMemTotal` + `measureRAM`
  - Displayed as: `Memory: used / total`
- **Swap file usage** (`measureSWAP`) (available, just not foregrounded visually in all layouts)
- **System uptime**:
  - `measureUptime` → `MeterUptimeTitle` + `meterUptime`
  - Format: `X Days, Y Hours, Z Minutes`
- **CPU name** from registry (`MeasureCPUName`)

### Storage / SMART Telemetry

Per-drive SMART via HWiNFO plugin:

- `SMARTFAIL0`…`SMARTFAIL3` – “Fail / No” status  
- `SMARTWARN0`…`SMARTWARN3` – warning status (pre-fail conditions)  
- `SMARTLIFE0` / `SMARTLIFE1` – drive life remaining  
- `measure1`, `measure2`, `measure3`, `measure4` – per-drive temperatures

Used for:

- Showing active drive temps in °C  
- Quick surface-level health indicator on the LCD so you see if anything is dying.

### Cooling / Loop Monitoring

- **Pump RPM** (`Pump_RPM` → `Pump_RPMs` meter)
  - `P: <rpm> RPM`
- **Radiator temperature**:
  - `measure5` (current), `measure5Max` (max)
  - Output as: `RAD: <current>°C|<max>°C`

### “Top Process” View

Using `AdvancedCPU.dll`:

- `m.TopProcess` – name of the current top CPU process  
- `m.TopProcess%` – its CPU usage %  
- Mapped into:
  - `meterTitleTopProcess` – “Top Process:” label  
  - `meterTopProcess` and `meterTopProcess%` – name + % side by side  

You basically get a **live “what’s eating my CPU” banner** on the LCD.

### Total Power (Combined Draw)

- `CalcTotalPower` currently sums `GPU_TOTAL_PWR + 0`  
  - Ready to incorporate CPU power (`CPU_Power`) when you want to flip it back on  
- Displayed via `TotalPower` meter as:
  - `Power Draw: <watts>`
---

## 🧰 Technology Stack

### Application Environment

- **Windows + Rainmeter** – skin engine and rendering  
- **HWiNFO** – sensor telemetry (CPU, GPU, drives, temps, power)  
- **MSI Afterburner** – FPS + GPU usage integration  
- **AdvancedCPU.dll** – top-process detection  
- **Mini 1920×480 LCD panel** – hardware target (HUD under main display)

### Code & Config

- **Rainmeter `.ini` skin** (`CrystalTelemetry.ini` or equivalent)
  - Measures for CPU, GPU, drives, loop, FPS, RAM, uptime
  - Meters for structured, glass-style layout
- **Lua** (optional helper scripts in the project)
  - Used for extendable logic / formatting where Rainmeter expressions get nasty
- **C++ plugin backends**
  - HWiNFO plugin  
  - MSI Afterburner plugin  
  - AdvancedCPU plugin  

---

## Structure (High Level)

Typical structure in this repo:

```text
Crystal-LCD/
  CrystalTelemetry.ini        # Main Rainmeter skin for the LCD
  @Resources/
    Variables.inc             # Colors, fonts, sizing, shared variables
    Sensors.inc               # HWiNFO / MSI ID mappings (per-machine)
    Images/                   # Backgrounds, reflection overlays, etc.
  assets/
    LCD.gif                   # Demo animation for README
