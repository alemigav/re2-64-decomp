/* FUN_801653a0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801653a0  body 0x801653a0..0x801653fb  size 92 B
 * body sha256 c267f383cf2dc3846425f3426e856a0e457ed095c77bb8e46df537c88db71762
 * recovered byte-exact (import by content alignment: 23 of 23 words at our own address (func_80165320_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/801653a0.c
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
typedef float f32;
typedef double f64;

s32 func_80164E08_overlay_026(void *arg0, s32 arg1, s32 arg2);
s32 func_80165290_ovl_26(void *arg0, s32 arg1, s32 arg2);
void func_80165320_ovl_26(void *arg0, s32 arg1, s32 arg2) {
 if (*(u8 *)((u8 *)arg0+6)==0) {
  func_80165290_ovl_26(arg0,2,6);
 }
 func_80164E08_overlay_026(arg0,arg1,arg2);
}
