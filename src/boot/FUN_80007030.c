/* FUN_80007030
 * image   boot (boot), base 0x80000480
 * address 0x80007030  body 0x80007030..0x800070b3  size 135 B
 * sha256  088b67fe9cb086a15909115372df87caa6f87fc9d95d6da74bc689db5f764ffa
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80007030(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = FUN_800072e0();
  iVar4 = FUN_80007000();
  iVar2 = _DAT_8001782c;
  iVar1 = _DAT_80017828;
  uVar5 = iVar4 - _DAT_80017820;
  FUN_80007300(uVar3);
  return iVar1 + (uint)(iVar2 + uVar5 < uVar5);
}
