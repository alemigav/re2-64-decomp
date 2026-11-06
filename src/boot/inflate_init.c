/* inflate_init
 * image   boot (boot), base 0x80000480
 * address 0x80004550  body 0x80004550..0x80004593  size 68 B
 * body sha256 16650798b1394c228e95b4fbfb14c78084014fd87c61399dd73aa6171d8952ff
 * recovered byte-exact (import: 17 of 17 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80004550_SOURCE
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
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

M2C_UNK func_800013B0(M2C_UNK);                     
s32 func_800013D4(M2C_UNK);                         

void *func_80004550(void *arg0, M2C_UNK arg1) {
    (*(s32 *)((s8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    func_800013B0(arg1);
    (*(s32 *)((s8 *)(arg0) + (0x4C))) = func_800013D4(0x8000);
    return arg0;
}
