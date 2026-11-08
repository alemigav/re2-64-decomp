/* FUN_800022bc
 * image   boot (boot), base 0x80000480
 * address 0x800022bc  body 0x800022bc..0x80002313  size 88 B
 * body sha256 8270198f176109fdb272427bfefc5a99a4236ecbc16b47019317b362e22a03f2
 * recovered byte-exact (read from the words (M382): 22 of 22, twenty-two words, one call then two indirect calls through the same slot with different arguments -- the second passes the first parameter as its own)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/800022bc.c
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

extern s32 FUN_80001510(void);

s32 FUN_800022bc(u8 *a, u8 *b)
{
    FUN_80001510();
    (*(s32 (**)(u32, u32))(b + 36))(*(u32 *)(b + 40), *(u32 *)(a + 36));
    (*(s32 (**)(u32, u8 *))(b + 36))(*(u32 *)(b + 40), a);
    return 0;
}
