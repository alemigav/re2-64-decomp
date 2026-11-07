/* FUN_80028780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028780  body 0x80028780..0x800288bf  size 320 B
 * body sha256 cd14460a2e8eaa0e3cd69d9bbd689f3249f7fbf9ce9adaf3f36968875f104daa
 * recovered byte-exact (import by content alignment: 80 of 80 words at our own address (func_800287B0_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80028780_SOURCE
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
typedef s32 M2C_UNK;
M2C_UNK func_800285AC_ovl_01(void*);
s32 func_800287B0_ovl_01(void*a,s32 b){
 s32 t,v,r;
 t=(*(s32*)((s8 *)(a) + (0x10)));
 if(t==0xC8){(*(M2C_UNK(**)())((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0x10)))();(*(M2C_UNK(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0x174)))) + (0)))(a);(*(M2C_UNK(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0x14)))) + (8)))(a);(*(s32*)((s8 *)(a) + (0x10)))=0xC9;}else if(t!=0xC9){(*(s32*)((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0x14)))=0xE;(*(s32*)((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0x18)))=(*(s32*)((s8 *)(a) + (0x10)));(*(M2C_UNK(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0)))(a);}
 r=(*(s32(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0x174)))) + (4)))(a);
 if(r==1)goto one;
 if(r<2){if(r) return r;func_800285AC_ovl_01(a);v=0xCA;goto set;}
 return r;
 one:
 if((*(s32*)((s8 *)((*(void**)((s8 *)(a) + (0x174)))) + (0x54)))){(*(s32*)((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0x14)))=0x33;(*(M2C_UNK(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0)))(a);}
 if(b){(*(s32*)((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0x14)))=0x2B;(*(M2C_UNK(**)(void*))((s8 *)((*(void**)((s8 *)(a) + (0)))) + (0)))(a);}
 v=0xC8;
 set:(*(s32*)((s8 *)(a) + (0x10)))=v;return r;
}
