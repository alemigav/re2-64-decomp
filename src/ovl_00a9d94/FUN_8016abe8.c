/* FUN_8016abe8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016abe8  body 0x8016abe8..0x8016ad0f  size 296 B
 * body sha256 2fbd4cc6511d88ca1ef556aea0fc59ceb046a17959b8fe380065271d1c10824f
 * recovered byte-exact (import by content alignment: 74 of 74 words at our own address (func_8016AB68_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/8016abe8.c
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
extern s8 D_8016C418_ovl_31[];
void func_8016AB68_ovl_31(void *arg0,void *arg1) {
 u8 state; s32 one=1; void *p;
 state=*(u8*)((u8*)arg0+0x2C5);
 switch(state) {
 case 0:
  *(u8*)((u8*)arg0+0x2C3)=0; *(u8*)((u8*)arg0+0x2C5)=one; *(s16*)((u8*)arg0+0x2C6)=0x78;
 case 1:
  if(*(u8*)((u8*)arg0+0x2C3)==0x3F) *(u8*)((u8*)arg0+0x2C5)=2;
  p=*(void**)((u8*)arg1+0x120);
  *(u16*)((u8*)p+0x10)=(u16)(((s32)(*(u16*)((u8*)p+0x10)<<16))>>17);
  p=*(void**)((u8*)arg1+0x120);
  *(u16*)((u8*)p+0x14)=(u16)(((s32)(*(u16*)((u8*)p+0x14)<<16))>>17);
  p=*(void**)((u8*)arg1+0x120); *(s16*)((u8*)p+0x18)=D_8016C418_ovl_31[*(u8*)((u8*)arg0+0x2C3)]*16; break;
 case 2:
  if(*(u8*)((u8*)arg0+0x2C3)==0x3F) *(u8*)((u8*)arg0+0x2C5)=3;
  p=*(void**)((u8*)arg1+0x120); *(u16*)((u8*)p+0x10)=D_8016C418_ovl_31[*(u8*)((u8*)arg0+0x2C3)]*16; break;
 case 3:
  if(*(u8*)((u8*)arg0+0x2C3)==0x3F) *(u8*)((u8*)arg0+0x2C5)=one;
  p=*(void**)((u8*)arg1+0x120); *(u16*)((u8*)p+0x14)=D_8016C418_ovl_31[*(u8*)((u8*)arg0+0x2C3)]*16; break;
 }
 *(u8*)((u8*)arg0+0x2C3)=(*(u8*)((u8*)arg0+0x2C3)+1)&0x3F;
}
