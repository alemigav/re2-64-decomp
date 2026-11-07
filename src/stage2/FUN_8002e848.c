/* FUN_8002e848
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e848  body 0x8002e848..0x8002e86b  size 36 B
 * body sha256 46517bcf065d11f576d2bff46aba0e0dc0ff9e47589bc21f7724b85b0343ba5f
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_8002E878))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002E848_SOURCE
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
typedef struct {void *field0; void *field4; void *field8; void *fieldc;} V;
void func_8002E878(void *arg0){
 char loc[0xC8];
 V *obj=(V*)arg0;
 ((void(*)(void *, void *))((V*)obj->field0)->fieldc)(arg0, loc);
}
