/* FUN_80164dec
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164dec  body 0x80164dec..0x80164e0f  size 36 B
 * body sha256 255fc6a789b9bd09f057fcb3a6d99a4a8503d30df42f077f1addb262548f7da5
 * recovered byte-exact (read from the words (M379): 9 of 9, nine words, a no-argument indirect call through a global function pointer)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009aed0/80164dec.c
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

extern void (*D_80166638)(void);

void FUN_80164dec(void)
{
    D_80166638();
}
