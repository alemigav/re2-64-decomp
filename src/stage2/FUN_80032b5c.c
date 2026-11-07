/* FUN_80032b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b5c  body 0x80032b5c..0x80032bd7  size 124 B
 * body sha256 3a116520493d5e207666dfd5ef99dc6255a704cfa0f278e1561d361ab06a9e38
 * recovered byte-exact (import by content alignment: 31 of 31 words at our own address (func_80032B8C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80032B5C_SOURCE
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
                                                
                                     
                                            
                                     
             
 
void func_80032B8C_ovl_01(void *p, s32 a) {
    s16 h[4];
    s32 tmp[8];
    h[0]=0; h[1]=*(u16*)((u8*)p+0x66)+a; h[2]=0;
    func_80040E88_ovl_01(h,tmp);
    func_8004279C_ovl_01(tmp,(u8*)p+0x1e0,h);
    *(s32*)((u8*)p+0x28)+=h[0];
    *(s32*)((u8*)p+0x30)+=h[2];
}
void func_80032C08_ovl_01(void *p, s32 a, s32 b) ;
                         
                                                                     
                                
                                             
                               
                               
                               
 
void func_80032C9C_ovl_01(void *p, s32 a, s32 b) ;
                                      
                                                                     
                                
                                                        
                                              
                               
                               
                               
 
