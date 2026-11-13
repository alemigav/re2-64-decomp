/* FUN_801665e8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801665e8  body 0x801665e8..0x8016664b  size 100 B
 * body sha256 45f7a97dc54e8446272c5cd575e67ac5da142894a3284a6dcf4dd1fb271b263c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b08a2/801665e8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_80167340;
extern unsigned int DAT_801673c8;
extern unsigned int DAT_80167440;












void FUN_801665e8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167340,param_2);
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_801673c8,uVar1);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167440,uVar1);
  return;
}
