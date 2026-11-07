/* FUN_800a5c50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c50  body 0x800a5c50..0x800a5c97  size 72 B
 * body sha256 eb469f57a44fa3b2abaeebfb092c30674003f45d51abda1d22853729e5417345
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_800A5BF0_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800A5C50_SOURCE
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
void func_8000EFA0(void *, s32);

void func_800A5BF0_ovl_01(u8 *arg0, s32 arg1) {
    u16 *src = (u16 *)arg0;
    u16 *dst = (u16 *)(arg1 * 2 + (s32)arg0);

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    func_8000EFA0(dst, 8);
}

extern u8 *D_80143EAC;

s32 func_800A5BA8_ovl_01(s32 arg0) ;
                                                     
 

extern s32 (*D_80143FA4)(void);

s32 func_800A5C38_ovl_01(s32 arg0) ;
                              

                          
                 
     
                          
                 
     
                        
    
                
 
