/* FUN_80004c9c
 * image   boot (boot), base 0x80000480
 * address 0x80004c9c  body 0x80004c9c..0x80004cfb  size 99 B
 * sha256  2ec2243c7c5c1b63f457b616ec63ca867d94283e7e3f80a410f6f13cd1422fca
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80004c9c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  piVar2 = (int *)(param_1 * 8 + _DAT_80012874);
  uVar3 = piVar2[1];
  uVar1 = 0;
  if (uVar3 != 0) {
    if ((uVar3 & 1) != 0) {
      uVar3 = uVar3 + 1;
    }
    func_0x800888ec(_DAT_800128a8 + *piVar2 + uVar3,auStack_10,8);
    uVar1 = local_c;
  }
  return uVar1;
}
