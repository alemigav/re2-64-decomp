/* FUN_800053f4
 * image   boot (boot), base 0x80000480
 * address 0x800053f4  body 0x800053f4..0x80005437  size 71 B
 * body sha256 2b4252563c76775018b8a19976658787de80e3c097546a742a7f4337c54be389
 * provider record sha256 c6d406bcd45ea42f596d4342cd72da680167ee8d955ea8822ab1f11b0545e38e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800053f4(undefined2 *param_1)

{
  _DAT_8001289c = param_1 + 2;
  _DAT_800128a4 = 0x20;
  _DAT_800128a0 = CONCAT22(param_1[1],*param_1);
  return;
}
