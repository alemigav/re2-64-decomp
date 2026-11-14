/* FUN_8004794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004794c  body 0x8004794c..0x80047983  size 56 B
 * body sha256 dcb375e25bf0140047eafde2dbd48509be3430751adc9d05c7c70874599ddae5
 * recovered byte-exact (imported: m2c's draft, better than the provider's (9 of 14 -> 14 of 14) and pinned word for word (M415))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004794c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
void func_8004794c(void *arg0, s8 arg1, s8 arg2, s8 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8) {
    (*(s8 *)((s8 *)(arg0) + (8))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (9))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (0x10))) = arg3;
    (*(s8 *)((s8 *)(arg0) + (0x11))) = (s8) arg4;
    (*(s8 *)((s8 *)(arg0) + (0x18))) = (s8) arg5;
    (*(s8 *)((s8 *)(arg0) + (0x19))) = (s8) arg6;
    (*(s8 *)((s8 *)(arg0) + (0x20))) = (s8) arg7;
    (*(s8 *)((s8 *)(arg0) + (0x21))) = (s8) arg8;
}
