/* FUN_8000d428
 * image   boot (boot), base 0x80000480
 * address 0x8000d428  body 0x8000d428..0x8000d45b  size 52 B
 * body sha256 78a518e10d3ed24f0242ec6825c6d6d8f895a3b33f42b47746a90ec8231d07be
 * recovered byte-exact (call13 family: 13 of 13 words -- a call through the unchanged arguments, returning a0 + a2)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as CALL13_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

extern void FUN_8000de9c(u32 a0, u32 a1, u32 a2);

u32 FUN_call13(u32 a0, u32 a1, u32 a2)
{
    FUN_8000de9c(a0, a1, a2);

    return a0 + a2;
}
