/* FUN_801669f4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801669f4  body 0x801669f4..0x80166a2f  size 60 B
 * body sha256 b456ec6a48cbd0e69238804ed050f9e12d27a163881249c8b946cb7385d18345
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/801669f4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167fd4;












void FUN_801669f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80167fd4)[*(byte *)(param_1 + 5)])(param_1,param_3,param_2);
  return;
}
