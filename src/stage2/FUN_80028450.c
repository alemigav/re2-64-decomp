/* FUN_80028450
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028450  body 0x80028450..0x800284f3  size 164 B
 * body sha256 8dc879c17c1835e09109f756b34ce52ab995d8bb772a047c1a042a4fb3c12ed3
 * recovered byte-exact (import by content alignment: 41 of 41 words at our own address (func_80028480_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80028450_SOURCE
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
void func_8002FC30_ovl_01(void *, s32, s32);
void func_80030D98_ovl_01(void *);
void func_8002D1B8_ovl_01(void *);

typedef struct {
    void **p0;
    u8 pad[0x174 - 4];
    u8 *p174;
} S540;

void func_80028540_ovl_01(S540 *arg0, u32 arg1, s32 arg2) ;
          

                       
                                          
               
     
                    
                   
                                                   
               
     
                                           
                                           
                                           
 

void func_80028480_ovl_01(u8 *arg0) {
    s32 temp;
    s32 i;

    temp = *(s32 *)(arg0 + 0);
    func_8002FC30_ovl_01(arg0, 0, 0x190);
    *(s32 *)(arg0 + 0xC) = 1;
    *(s32 *)(arg0 + 0) = temp;
    func_80030D98_ovl_01(arg0);
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    for (i = 3; i >= 0; i--) {
        *(s32 *)(arg0 + 0x7C + i * 4) = 0;
    }
    for (i = 0; i < 4; i++) {
        *(s32 *)(arg0 + 0x8C + i * 4) = 0;
        *(s32 *)(arg0 + 0x9C + i * 4) = 0;
    }
    *(s32 *)(arg0 + 0x114) = 0;
    *(s32 *)(arg0 + 0x174) = 0;
    func_8002D1B8_ovl_01(arg0);
    *(s32 *)(arg0 + 0x10) = 0xC8;
}

typedef struct {
    void *(*fn)(void *, s32, s32);
} Vtbl;

typedef struct {
    u8 pad[4];
    Vtbl *vt;
} Obj;

void func_8002844C_ovl_01(Obj *arg0) ;
                                                             
 

void func_80028420_ovl_01(Obj *arg0) ;
                                                           
 
