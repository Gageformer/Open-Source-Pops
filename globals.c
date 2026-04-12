/* POPS.ELF Decompiled - globals.c */
/* Global variable definitions for all extern declarations in pops_types.h */

#include "pops_types.h"
#include "functions.h"

/* MIPS R5900 register variables (used as locals in decompiled functions) */
u32 ret;             /* $v0 - return value / general result */
u32 v1;              /* $v1 */
u32 a0, a1, a2, a3;  /* $a0-$a3 - function arguments */
u32 t0, t1, t2, t3;  /* $t0-$t3 - temporaries (caller-saved) */
u32 t4, t5, t6, t7;  /* $t4-$t7 */
u32 s0, s1, s2, s3;  /* $s0-$s3 - saved (callee-saved) */
u32 s4, s5, s6, s7;  /* $s4-$s7 */
u32 t8, t9;           /* $t8-$t9 */
u32 __at;             /* $at - assembler temporary */
u32 __gp;             /* $gp - global pointer */
u32 __sp;             /* $sp - stack pointer */
u32 __fp;             /* $fp - frame pointer */
u32 __ra;             /* $ra - return address */
u32 __k0, __k1;       /* $k0-$k1 - kernel temporaries */

u32 HI, LO;           /* HI/LO multiply-divide registers */
u64 HI_LO;            /* Combined HI:LO for 64-bit multiply results */
u32 ac0, ac2, ac3;    /* EE multimedia accumulator registers (pipeline 0/1) */

u32 __cop0_reg[32];   /* COP0 registers */
u32 __fpu_reg[32];    /* FPU registers (as u32 bit patterns) */
u32 __fpu_cc;         /* FPU condition code flag (c.lt.s result) */

/* GP-relative global variables (emulator state) */
PSX_State *g_psx;            /* __gp - 0x7F60: main emulator state pointer */
u32 g_running;               /* __gp - 0x7F58: emulator running flag */
u32 g_bios_version;          /* __gp - 0x7F54: cached BIOS version */
u32 g_init_flag;             /* __gp - 0x7F4C: initialization state */
u32 g_irq_stat;              /* __gp - 0x7F10: interrupt status shadow */
u32 g_irq_mask;              /* __gp - 0x7F0C: interrupt mask shadow */
u32 g_counter_state;         /* __gp - 0x7F00: counter subsystem state */
u32 g_target_cycles;         /* __gp - 0x77EC: target cycle count */
u32 g_time_scale;            /* __gp - 0x77E8: timing scale factor */
u32 g_time_accum;            /* __gp - 0x77E4: timing accumulator */
u32 g_cycle_base;            /* __gp - 0x77E0: cycle base counter */
u32 g_jit_flag;              /* __gp - 0x77CC: JIT enable flag */
u32 g_jit_cache;             /* __gp - 0x77C8: JIT code cache pointer */
u32 g_jit_state;             /* __gp - 0x77C4: JIT compiler state */
u32 g_compiler_irq0;         /* __gp - 0x77C0: compiler/interrupt shared */
u32 g_compiler_irq1;         /* __gp - 0x77BC: compiler/interrupt shared */
u32 g_gpu_state;             /* __gp - 0x77B8: GPU state flag */
u32 g_gpu_ctrl;              /* __gp - 0x77B4: GPU control */
u32 g_serial_ctrl0;          /* __gp - 0x77B0: serial control 0 */
u32 g_serial_ctrl2;          /* __gp - 0x77A0: serial control 2 */
u32 g_memcard_flag;          /* __gp - 0x779C: memcard state flag */
u32 g_memcard_ctrl0;         /* __gp - 0x7798: memcard/serial shared */
u32 g_memcard_ctrl1;         /* __gp - 0x7794: memcard/serial shared */
u32 g_serial_base;           /* __gp - 0x7790: serial port base address */
u32 g_mdec_ctrl;             /* __gp - 0x7788: MDEC control state */
u32 g_cdrom_ctrl0;           /* __gp - 0x7768: CDROM control */
u32 g_cdrom_ctrl1;           /* __gp - 0x7764: CDROM control */
u32 g_cdrom_ctrl2;           /* __gp - 0x7760: CDROM control */
u32 g_cdrom_ctrl3;           /* __gp - 0x775C: CDROM control */
u32 g_spu_ctrl0;             /* __gp - 0x7758: SPU control */
u32 g_spu_ctrl1;             /* __gp - 0x7754: SPU control */
u32 g_spu_ctrl2;             /* __gp - 0x7750: SPU control */
u32 g_spu_ctrl3;             /* __gp - 0x774C: SPU control */
u32 g_spu_ctrl4;             /* __gp - 0x7748: SPU control */
u32 g_spu_ctrl6;             /* __gp - 0x7738: SPU control */

/* Additional globals found in source */
u32 g_bios_ver2;             /* secondary BIOS version */
u32 g_counter_base;          /* counter base address */
u32 g_hw_init_flag;          /* hardware init flag */
u32 g_hw_reg_base;           /* hardware register base */
u32 g_irq_stat2;             /* secondary IRQ status */
u32 g_irq_mask2;             /* secondary IRQ mask */
u32 g_event_active_list;     /* active event list head */
u32 g_event_free_list;       /* free event list head */
u32 g_event_pending;         /* pending events count */
u32 g_event_timeout;         /* event timeout value */
u32 g_cdrom_dma_flag;        /* CDROM DMA flag */
u32 g_cdrom_state0;          /* CDROM state 0 */
u32 g_cdrom_state1;          /* CDROM state 1 */
u32 g_cdrom_state2;          /* CDROM state 2 */
u32 g_cdrom_state3;          /* CDROM state 3 */
u32 g_mdec_state1;           /* MDEC state 1 */
u32 g_mdec_state2;           /* MDEC state 2 */
u32 g_mdec_state3;           /* MDEC state 3 */
u32 g_mdec_state4;           /* MDEC state 4 */
u32 g_mdec_state5;           /* MDEC state 5 */
u32 g_mdec_state6;           /* MDEC state 6 */
u32 g_spu_state0;            /* SPU state 0 */
u32 g_spu_state1;            /* SPU state 1 */
