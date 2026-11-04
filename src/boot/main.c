/* main
 * image   boot (boot), base 0x80000480
 * address 0x80000520  body 0x80000520..0x80000597  size 120 B
 * body sha256 27ba28eb391fcfa8318e0226becf075e1e9a67bfc00653eb471e0d5ba0574e62
 * recovered byte-exact (single: 30 of 30, one draft (the boot initialiser, `main`))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80000520_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

extern u32 __bss_start[];
extern u32 __bss_end[];
extern void FUN_800004f0(u32 a0);
extern void FUN_800070c0(void);
extern void FUN_80000598(void);

void FUN_x(void)
{
    u32 *p = __bss_start;
    u32 n = __bss_end - __bss_start;

    while (n--)
        *p++ = 0;
    FUN_800004f0(0);
    FUN_800070c0();
    while (*(u32 *)0x80000300u == 0)
        ;
    FUN_80000598();
}
