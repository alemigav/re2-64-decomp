/* func_800b1ec4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1ec4  body 0x800b1ec4..0x800b1fbf  size 255 B
 * body sha256 4201fc734419aa209245be415ef2691caa6abe46bcb0ecc6435e229508984675
 * provider record sha256 fd66c078cd6012787940348236ca3267760047a1641f3d0af449568bdbe73afc
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b1ec4(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar1;
  int in_v0;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar2 = FUN_800af0d4(param_1);
    while (uVar2 != 0xffffffff) {
      uVar4 = uVar2 & 0xff;
      iVar3 = uVar4 * 0x1a0;
      if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
      if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
      }
      else {
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
      }
      FUN_800ac614(0x40,uVar4,uVar1,param_2);
      uVar5 = 0;
      uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    }
    FUN_800a56c0();
  }
  return uVar5;
}
