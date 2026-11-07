/* FUN_80032c6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032c6c  body 0x80032c6c..0x80032d13  size 168 B
 * body sha256 82ddc64ea03b59ad22d745fa687c321165c8abbcda305c07e185422345764ec1
 * recovered byte-exact (import by content alignment: 42 of 42 words at our own address (func_80032C9C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80032C6C_SOURCE
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
s32 func_80032B40_ovl_01(void *p, s16 *b) ;
                                                
                                     
                                            
                                     
             
 
void func_80032B8C_ovl_01(void *p, s32 a) ;
             
               
                                                
                                
                                             
                               
                               
 
void func_80032C08_ovl_01(void *p, s32 a, s32 b) ;
                         
                                                                     
                                
                                             
                               
                               
                               
 
void func_80032C9C_ovl_01(void *p, s32 a, s32 b) {
    s16 h[4]; s32 tmp[8]; s32 tmp2[8];
    h[0]=0; h[1]=*(u16*)((u8*)p+0x66)+a; h[2]=*(u16*)((u8*)p+0x68)+b;
    func_80040E88_ovl_01(h,tmp);
    func_8004251C_ovl_01(*(s32*)((u8*)p+0x70),tmp,tmp2);
    func_8004279C_ovl_01(tmp2,(u8*)p+0x1e0,h);
    *(s32*)((u8*)p+0x28)+=h[0];
    *(s32*)((u8*)p+0x2c)+=h[1];
    *(s32*)((u8*)p+0x30)+=h[2];
}
