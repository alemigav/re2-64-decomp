/* FUN_80058e18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058e18  body 0x80058e18..0x80059093  size 639 B
 * sha256  1ac9d9017da551a6054ff176ebfe58eb7356be02222a4aba4ca049c15f73cf82
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80058e18(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined4 uVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    *(int *)(param_1 + 0x1e8) =
         *(short *)(&DAT_8010dca0 + *(char *)(param_1 + 0x1ed) * 2) * 0x1000000 + 0x700;
  case 1:
    if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
      FUN_80077f30(1,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 4;
    }
    FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
    uVar1 = *(ushort *)(param_1 + 0x66);
    if ((uVar1 & 0x200) == 0) {
      uVar2 = -(uVar1 >> 2 & 0xff);
    }
    else {
      uVar2 = uVar1 >> 2 & 0xff;
    }
    *(ushort *)(param_1 + 0x66) = uVar1 + uVar2;
    if ((*(ushort *)(param_1 + 0x66) & 0x3e0) == 0) {
      *(ushort *)(param_1 + 0x66) = *(ushort *)(param_1 + 0x66) & 0xff00;
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    *(undefined1 *)(param_1 + 6) = 3;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000700;
  case 3:
    uVar4 = 0x200;
    goto LAB_80059054;
  case 4:
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000700;
  case 5:
    if (*(char *)(param_1 + 0x1e9) == '\x01') {
      FUN_80077adc(0x2040001,param_1 + 0x28);
      FUN_80052bd0(2,0);
      FUN_80052c6c(3,0x96,0);
      FUN_80052d10(0x14,0x96,0,3);
    }
    FUN_80089d54(param_1,param_2,param_3,0x200);
    if (*(char *)(param_1 + 8) == '\x0f') {
      *(undefined2 *)(param_1 + 0x1e0) = 5;
    }
    if ((**(uint **)(param_1 + 0x214) & 0x2000) == 0) {
      *(undefined2 *)(param_1 + 0x1e4) = 0;
    }
    else {
      FUN_80033680(param_1,1,*(char *)(param_1 + 8) == '\x0f');
      *(undefined2 *)(param_1 + 0x1e4) = 0;
    }
    FUN_80032b5c(param_1,0);
    break;
  case 6:
    uVar4 = 0x10200;
LAB_80059054:
    cVar3 = FUN_80089d54(param_1,param_2,param_3,uVar4);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    break;
  case 7:
    FUN_800551e0();
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}
