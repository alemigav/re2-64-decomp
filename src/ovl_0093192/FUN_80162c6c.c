/* FUN_80162c6c
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162c6c  body 0x80162c6c..0x80162c8f  size 36 B
 * body sha256 a0ee89b533e01c896ec55db5d9f58e169d862b66e412caf2e430b5844fdd0e2a
 * recovered byte-exact (read from the words (M379): 9 of 9, nine words, four byte stores then a flag set in the same record -- the load hoists above the stores because the offsets prove no alias)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0093192/80162c6c.c
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

void FUN_80162c6c(u8 *p, u8 v)
{
    p[4] = 2;
    p[5] = v;
    p[6] = 0;
    p[7] = 0;
    p[623] |= 0x80;
}
