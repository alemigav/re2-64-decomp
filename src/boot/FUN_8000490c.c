/* FUN_8000490c
 * image   boot (boot), base 0x80000480
 * address 0x8000490c  body 0x8000490c..0x80004927  size 28 B
 * body sha256 bb2e1b373c581d2dcec22bd66ddf31d035302be5507583c3283d370a2cfa1f73
 * recovered byte-exact (read from the words (M384): 7 of 7, seven words, a wrapper that calls with its second argument -- `addu $a0,$a1,$zero` in the delay slot is the whole body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000490c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_800014ac(u32 v);

void FUN_8000490c(u32 a, u32 b)
{
    FUN_800014ac(b);
}
