/* func_800b1c78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1c78  body 0x800b1c78..0x800b1db7  size 323 B
 * body sha256 0b44f4a8528ce6cae9e703464da7511c7db2f33a44e417bd2cbc75d689e78d5e
 * provider record sha256 2ffaff34dcce99f07f2b520bc47435e304a7c2420d8808ea34b9a404b16f8162
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b1c78(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  int in_v0;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    uVar2 = FUN_800af0d4(param_1);
    if (uVar2 != 0xffffffff) {
      uVar6 = (param_2 & 0xffff) >> 7;
      do {
        uVar4 = uVar2 & 0xff;
        iVar3 = uVar4 * 0x1a0;
        if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
        if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
          FUN_800ac614(1,uVar4,*(undefined1 *)(iVar3 + -0x7febbb6d),uVar6 & 0xff);
          uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
        }
        else {
          FUN_800ac614(1,uVar4,*(undefined1 *)(iVar3 + -0x7febbb63),uVar6 & 0xff);
          uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
        }
        FUN_800ac614(0x21,uVar4,uVar1,param_2 & 0x7f);
        uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
        uVar5 = 0;
      } while (uVar2 != 0xffffffff);
    }
    FUN_800a56c0();
  }
  return uVar5;
}
