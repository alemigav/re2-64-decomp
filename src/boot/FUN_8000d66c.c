/* FUN_8000d66c
 * image   boot (boot), base 0x80000480
 * address 0x8000d66c  body 0x8000d66c..0x8000d697  size 44 B
 * body sha256 8bd4bcfe3d2f19651acf68475bc003cba07fc888aa711296ca298600782cf616
 * recovered byte-exact (read from the words (M379): 11 of 11, eleven words, a wait loop on a callee's result then a one-argument call with 0x125 -- the boot image's first reconstruction in this band)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000d66c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 FUN_8000d9c0(void);
extern void FUN_8000db10(u32 n);

void FUN_8000d66c(void)
{
    while (FUN_8000d9c0() != 0) {
    }
    FUN_8000db10(0x125);
}
