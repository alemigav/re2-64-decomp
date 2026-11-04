/* FUN_801630bc
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801630bc  body 0x801630bc..0x801630e7  size 44 B
 * body sha256 c8329eadc375913d573099c939bfc552f2b54ef409403aa45e97c3be39508032
 * recovered byte-exact (loop family: 11 of 11 words, one shape for both copies (counter initialised before the pointer read))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as LOOP11_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

void FUN_loop11(u32 a0)
{
    u32 i = 0;
    u32 *v = *(u32 **)(a0 + 564);

    while (i < 22)
    {
        *v = *v | 0x8000u;
        v = (u32 *)((u32)v + 0x178);
        i++;
    }
}
