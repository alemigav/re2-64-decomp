/* FUN_8000de9c
 * image   boot (boot), base 0x80000480
 * address 0x8000de9c  body 0x8000de9c..0x8000dec3  size 40 B
 * body sha256 ad8cb30bcc83138175f2d7ed54f9520da44bec4801f84e83c2e128b5190d8549
 * recovered byte-exact (read from the words (M370): 10 of 10, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000de9c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u8 *FUN_8000de9c(u8 *a0, u8 *a1, u32 a2)
{
    u8 *p = a0;

    if (a2 != 0) {
        do {
            *p = *a1;
            a1++;
            a2--;
            p++;
        } while (a2 != 0);
    }

    return a0;
}
