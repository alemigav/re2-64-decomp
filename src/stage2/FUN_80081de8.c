/* FUN_80081de8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081de8  body 0x80081de8..0x80081f4b  size 359 B
 * sha256  f2c5959d1b198acb9617ba454155ec62aa0ab20187420e20a1aadb3039728671
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80081de8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
               (int)(((uint)(*(ushort *)(param_1 + 0x1e0) >> 0xf) * -2 + 1) *
                     (int)*(short *)(param_1 + 0x270) * 0x10000) >> 0x10);
  FUN_80032b5c(param_1,0);
  uVar3 = **(uint **)(param_1 + 0x214);
  if ((uVar3 & 0x4000) != 0) {
    if (*(char *)(param_1 + 5) == '\x05') {
      FUN_80077f30(1,((uVar3 & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 4;
    }
    else {
      FUN_80077f30(0,((uVar3 & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 2;
    }
  }
  FUN_80089d54(param_1,param_2,param_3,0x200);
  iVar1 = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x260);
  iVar2 = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x262);
  iVar1 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  return iVar1 < 100;
}
