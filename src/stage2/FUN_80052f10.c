/* FUN_80052f10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052f10  body 0x80052f10..0x80052f3b  size 44 B
 * body sha256 cd00fbdbc17c885f6a4470d4792a96b55db4e143b1e7e4198293c2a79e500951
 * recovered byte-exact (imported: m2c's draft, better than the provider's (10 of 11 -> 11 of 11) and pinned word for word (M415))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80052f10.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
u32 func_80052f10(u8 *arg0) {
    u32 var_a1;
    u32 var_v1;
    u8 *var_a0;

    var_a0 = arg0;
    var_a1 = 0;
    var_v1 = 0;
    do {
        if (*var_a0 != 0) {
            var_a1 += 1;
        }
        var_v1 += 1;
        var_a0 += 0xA;
    } while (var_v1 < 0x20U);
    return var_a1;
}
