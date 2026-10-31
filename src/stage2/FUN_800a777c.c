/* FUN_800a777c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a777c  body 0x800a777c..0x800a7853  size 219 B
 * sha256  28f49f7a0394a02c3b64efbe441f06f8ebf3f745f536ba2b5a0e37ad5b2c592d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a777c(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  uVar2 = FUN_800af0d4();
  while( true ) {
    if (uVar2 == 0xffffffff) {
      return uVar5;
    }
    uVar4 = uVar2 & 0xff;
    iVar3 = uVar4 * 0x1a0;
    if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
    if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
      uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
    }
    else {
      uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
    }
    FUN_800ac614(0x83,uVar4,uVar1,param_2);
    uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    uVar5 = 0;
  }
  return uVar5;
}
