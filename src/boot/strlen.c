/* strlen
 * image   boot (boot), base 0x80000480
 * address 0x8000de78  body 0x8000de78..0x8000de9b  size 36 B
 * body sha256 6b211db9362eeae3137dd832164db2058dd1f00dbb2ab3b442df8a801e2a08ef
 * recovered byte-exact (read from the words (M370): 9 of 9, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000de78.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u32 FUN_8000de78(u8 *a0)
{
    u8 *p = a0;

    if (*p != 0) {
        do {
            p++;
        } while (*p != 0);
    }

    return p - a0;
}
