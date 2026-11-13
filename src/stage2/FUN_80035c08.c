/* FUN_80035c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035c08  body 0x80035c08..0x80035c9b  size 148 B
 * body sha256 90efa689ad7220bd6b82809ab257913fec244112f9099986b50cb61b2da95e0d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80035c08.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_800eb414;
extern unsigned int DAT_800eb4a8;
extern unsigned int DAT_800eb53c;
extern unsigned int DAT_800eb604;
extern unsigned int DAT_800eb684;












void FUN_80035c08(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb414,param_2);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb4a8,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb53c,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb604,uVar1);
  FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb684,uVar1);
  return;
}
