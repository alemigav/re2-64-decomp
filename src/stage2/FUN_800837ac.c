/* FUN_800837ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837ac  body 0x800837ac..0x800837cf  size 36 B
 * body sha256 12439462b6fe920fc508819890d40489f71f213a4fb30251687f2cfd27136e9b
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_800837DC_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800837AC_SOURCE
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
void func_800837B0_ovl_01(s32 *arg0, u32 arg1) ;
                                                       
 

void func_80083788_ovl_01(s32 *arg0, u32 arg1) ;
                                                    
 

s32 func_800837DC_ovl_01(s32 *arg0, u32 arg1) {
    return arg0[arg1 >> 5] & (0x80000000U >> (arg1 & 0x1F));
}

void func_80083778_ovl_01(void) ;
 
