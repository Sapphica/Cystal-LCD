[Variables]
; CPU #0
;===== Required Data =====
CPU0-SensorID=0xf7067930
;CPU0-SensorID=0xf0000300
CPU0-SensorInstance=0x0
;===== Voltage ======
CPU0-C0-Volt=0x2000000
CPU0-C1-Volt=0x2000001
CPU0-C2-Volt=0x2000002
CPU0-C3-Volt=0x2000003
;===== Clock =====
;CPU0-C0-Clock=0x6000000
CPU0-C1-Clock=0x6000001
CPU0-C2-Clock=0x6000002
CPU0-C3-Clock=0x6000003
;===== Threads =====
CPU0-T0-CurrentUsage=0x7000000
CPU0-T1-CurrentUsage=0x7000001
CPU0-T2-CurrentUsage=0x7000002
CPU0-T3-CurrentUsage=0x7000003
CPU0-T4-CurrentUsage=0x7000004
CPU0-T5-CurrentUsage=0x7000005
CPU0-T6-CurrentUsage=0x7000006
CPU0-T7-CurrentUsage=0x7000007

;===== Required Data =====
CPUCLK-SensorID=0xf0000300
CPUCLK-SensorInstance=0x0
CPUCLK-C0-Clock=0x6000000



; CPU #0 Temps
;===== Required Data =====
;CPU0-Temp-SensorID=0xf0000400
CPU0-Temp-SensorID=0xf0000400
;CPU0-Temp-SensorInstance=0x0
CPU0-Temp-SensorInstance=0x0
;===== Core Temps =====

;CPU0-C0-Temp=0x1000000
CPU0-C0-Temp=0x10000ff
CPU0-C1-Temp=0x1000001
CPU0-C2-Temp=0x1000002
CPU0-C3-Temp=0x1000003

;T Temp Sensor
T-Temp-SensorID=0xf0ec0502
T-Temp-SensorInstance=0x0
T-Temp=0x1000002

; CPU #0 GPU Data
;===== Required Data =====
CPU0-GPU0-SensorID=0xf0000300
CPU0-GPU0-SensorInstance=0x0
;===== Stats =====
CPU0-GPU0-Clock=0x6000000
CPU0-GPU0-Usage=0x7000000
CPU0-GPU0-Memory=0x8000002

;CPU0-Power
CPU-Power-SensorID=0xf0ec0502
CPU-Power-SensorInstance=0x0
CPU-Power=0x5000000

; System Memory
;===== Required Data =====
System-SensorID=0xf0000301
System-SensorInstance=0x0
;===== Virtual Memory =====
System-Virt-Committed=0x8000000
System-Virt-Available=0x8000001
System-Virt-Load=0x8000002
;===== Physical Memory =====
System-Ram-Used=0x8000003
System-Ram-Available=0x8000004
System-Ram-Load=0x8000005


; Dedicated GPU
;===== Required Data =====
GPU0-SensorID=0xe0002000
GPU0-SensorInstance=0x0
;===== Stats =====
GPU0-Temp=0x1000000
GPU0-Volt=0x2000000
GPU0-Fan=0x8000000
GPU0-Fan-RPM=0x3000000
GPU0-Core-Clock=0x6000000
GPU0-Mem-Clock=0x6000004
GPU0-Vid-Clock=0x6000005
GPU0-Core-Load=0x7000000
GPU0-Mem-Usage=0x7000008
GPU0-Mem-Allocated=0x80000fc
GPU0-Power-Norm=0x800003a
GPU0-Power=0x5000000
GPU0-PCIe-Speed=0x80000ff

; Dedicated GPU

;===== Required Data =====
/GPU1-SensorID=0xe0002000
/GPU1-SensorInstance=0x14
;===== Stats =====
GPU1-Temp=0x1000000
GPU1-Volt=0x2000000
GPU1-Fan=0x8000000
GPU1-Fan-RPM=0x3000000
GPU1-Core-Clock=0x6000000
GPU1-Mem-Clock=0x6000004
GPU1-Vid-Clock=0x6000005
GPU1-Core-Load=0x7000000
GPU1-Mem-Usage=0x7000008
GPU1-Mem-Allocated=0x80000fc
GPU1-Power-Norm=0x800003a
GPU1-Power=0x800003b
GPU1-PCIe-Speed=0x80000ff


; HDD0 S.M.A.R.T.
;===== Required Data =====
HDD0-SMART-SensorID=0xf0000100
HDD0-SMART-SensorInstance=0x0
;===== S.M.A.R.T. Stats =====
HDD0-Temp=0x1000001
HDD0-Drive-Fail=0x8000000
HDD0-Drive-Warning=0x8000001
HDD0-Drive-Life=0x7000000
; HDD 0
;===== Required Data =====
/HDD0-SensorID=0xf0000100
/HDD0-SensorInstance=0x0
;===== Stats =====
/HDD0-Read-Per=0x7000000
/HDD0-Write-Per=0x7000001
/HDD0-Total-Per=0x8000002
/HDD0-Read-Rate=0x8000000
/HDD0-Write-Rate=0x8000001

; HDD1 S.M.A.R.T.
;===== Required Data =====
HDD1-SMART-SensorID=0xf0000100
HDD1-SMART-SensorInstance=0x1
;===== S.M.A.R.T. Stats =====
HDD1-Temp=0x1000001
HDD1-Drive-Fail=0x8000000
HDD1-Drive-Warning=0x8000001
HDD1-Drive-Life=0x7000000
; HDD1
;===== Required Data =====
HDD1-SensorID=0xf0000100
HDD1-SensorInstance=0x1
;===== Stats =====
HDD1-Read-Per=0x7000000
HDD1-Write-Per=0x7000001
HDD1-Total-Per=0x7000002
HDD1-Read-Rate=0x8000000
HDD1-Write-Rate=0x8000001

; HDD2 S.M.A.R.T.
;===== Required Data =====
HDD2-SMART-SensorID=0xf0000100
HDD2-SMART-SensorInstance=0x2
;===== S.M.A.R.T. Stats =====
HDD2-Temp=0x1000001
HDD2-Drive-Fail=0x8000000
HDD2-Drive-Warning=0x8000001

/End of Drives

; HDD2
;===== Required Data =====
HDD2-SensorID=0xf0000100
HDD2-SensorInstance=0x2
;===== Stats =====
HDD2-Read-Per=0x7000000
HDD2-Write-Per=0x7000001
HDD2-Total-Per=0x7000002
HDD2-Read-Rate=0x8000000
HDD2-Write-Rate=0x8000001

; HDD3 S.M.A.R.T.
;===== Required Data =====
HDD3-SMART-SensorID=0xf0000100
HDD3-SMART-SensorInstance=0x3
;===== S.M.A.R.T. Stats =====
HDD3-Temp=0x1000000
HDD3-Drive-Fail=0x8000000
HDD3-Drive-Warning=0x8000001


; HDD3
;===== Required Data =====
; HDD3-SensorID=0xf0000101
; HDD3-SensorInstance=0x3
;===== Stats =====
; HDD3-Read-Per=0x7000000
; HDD3-Write-Per=0x7000001
; HDD3-Total-Per=0x7000002
; HDD3-Read-Rate=0x8000000
; HDD3-Write-Rate=0x8000001


;  Fans
;Pump
Pump-SensorID=0xf7067930
Pump-SensorInstance=0x0
Pump-RPM=0x3000002
