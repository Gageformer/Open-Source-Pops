# Open Source POPS

A decompilation of Sony's POPS (PS1 emulator for PlayStation 2). The original `POPS.ELF` is a stripped MIPS R5900 binary from the PS2 HDD-based PS1 backward compatibility system.

The ELF is fully stripped with no symbol table. All 1,022 function names, subsystem boundaries, and struct layouts were reconstructed through static analysis.

Below is an AI summary of the work and contents created. As I have done this within my spare time and stared at many different components & breakdowns all at once, please do not mind such generated content.

### Source Files

| File | Functions | What it does |
|------|-----------|-------------|
| `main.c` | 6 | Entry point, startup |
| `psx.c` | 21 | PS1 init, event system, assertions |
| `r3000.c` | 59 | R3000A CPU emulation core |
| `compiler.c` | 69 | JIT recompiler / code cache |
| `interrupt.c` | 16 | PS1 interrupt controller |
| `dma.c` | 8 | PS1 DMA controller |
| `counter.c` | 8 | PS1 timers |
| `gpu.c` | 6 | PS1 GPU interface |
| `serial.c` | 30 | Controllers and memory cards (serial I/O) |
| `memcard.c` | 2 | Memory card file management |
| `mdec.c` | 48 | MDEC motion decoder (FMV playback) |
| `cdrom.c` | 41 | CD-ROM emulation |
| `spu.c` | 19 | Sound processing unit |
| `gte.c` | 79 | Geometry Transform Engine (3D math coprocessor) |
| `hdd.c` | 64 | HDD/PFS disc image I/O |
| `ui.c` | 178 | UI rendering, fonts, menus |
| `system.c` | 179 | TLB, SIF/IOP communication, boot sequence |
| `ee_kernel.c` | 73 | EE kernel wrappers, DMA debug |
| `memory.c` | 1 | Memory layout |
| `pad.c` | 1 | Pad init |
| `libc.c` | 114 | Embedded C library (printf, malloc, memcpy, etc.) |

### Verified Structs

Nine struct definitions have been verified against the binary through cross-referencing init routines, field access patterns, and known PS1 hardware layouts:

- **PSX_State** (0x2EC+ bytes) -- Core emulator state: PC, HI/LO, GPR[32], COP0[32], GTE data/ctrl registers, execution control
- **GTE_DataRegs / GTE_CtrlRegs** (128 bytes each) -- Geometry engine register files
- **DMA_Channel** (0x20 bytes, x7) -- Per-channel DMA state
- **Serial_Port** (0x1C bytes, x2) -- Controller/memcard port state
- **GPU_HandlerSlot** (0x1C bytes, x2) -- GPU command queue entries
- **SPU_State** (0x0C bytes) -- Sound processing state
- **JIT_CacheSlot** (0x10 bytes, x10) -- JIT recompiler cache entries
- **MDEC_Request** (0x28 bytes) -- Motion decoder request queue

## Binary Details

| Property | Value |
|----------|-------|
| Architecture | MIPS R5900 (Emotion Engine) |
| Endianness | Little-endian |
| ABI | EABI64, MIPS-III |
| Entry point | 0x00200008 |
| Code size | 296 KB (74,351 instructions) |
| Data size | 2.75 MB (includes 10 embedded IOP modules) |
| Symbols | None (fully stripped) |

## Embedded IOP Modules

The data section contains 10 IOP (I/O Processor) modules that get loaded at runtime:

- **sio2man** -- SIO2 manager (controller/memcard bus)
- **padman_hsync** -- Pad manager (hsync variant)
- **Sound_Device_Library (libsd)** -- SPU2 sound driver
- **sdr_driver** -- Sound driver relay
- **dev9** -- DEV9 expansion device (HDD/network)
- **atad** -- ATA device driver
- **hdd** -- HDD block device
- **pfs** -- PFS filesystem driver
- **IOPCD** (2 MB) -- Main CD-ROM emulation layer

## Current State

The decompilation covers all 1,022 functions. The output is structured C with named functions, typed register variables, struct field access for major subsystems, and reconstructed control flow. It is not yet a clean compile -- there are remaining inline assembly statements for EE-specific instructions, some unresolved cross-function jumps, and areas where the automated pipeline produced imperfect output that need manual cleanup.


## Legal

This project is for educational and preservation purposes. No original Sony source code was used.
