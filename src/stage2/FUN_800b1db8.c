/* FUN_800b1db8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1db8  body 0x800b1db8..0x800b1ebb  size 263 B
 * sha256  8627295305b745f5eff80e62c14e4df340268b99a4338876fb95cbfc23b32a89
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b1db8(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if (DAT_80136310 != '\0') {
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
      FUN_800ac614(0x5b,uVar4,uVar1,param_2);
      uVar5 = 0;
      uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    }
    FUN_800a56c0();
  }
  return uVar5;
}
