/* FUN_80165568
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165568  body 0x80165568..0x801655b3  size 76 B
 * body sha256 40d228376f4b6907322688b3c2f7ac51ca3487d2a0842bcf487c44ffb999a075
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00ae24a/80165568.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_8016731c;
extern unsigned int DAT_80167388;












void FUN_80165568(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_8016731c,param_2);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167388,uVar1);
  return;
}
