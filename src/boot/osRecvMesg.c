/* osRecvMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000c9e0  body 0x8000c9e0..0x8000cb03  size 295 B
 * sha256  9f1dda014b7b56833f326552a565eab30bd65df0bc191ea2e4e2ffa3a475f654
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 osRecvMesg(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_800072e0();
  iVar3 = *(int *)(param_1 + 8);
  while( true ) {
    if (iVar3 != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(*(int *)(param_1 + 0xc) * 4 + *(int *)(param_1 + 0x14));
      }
      iVar4 = *(int *)(param_1 + 0x10);
      iVar3 = *(int *)(param_1 + 0xc) + 1;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
        trap(0x1800);
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      *(int *)(param_1 + 0xc) = iVar3 % iVar4;
      if (**(int **)(param_1 + 4) != 0) {
        uVar2 = FUN_80000f50(param_1 + 4);
        osStartThread(uVar2);
      }
      FUN_80007300(uVar1);
      return 0;
    }
    if (param_3 == 0) break;
    *(undefined2 *)(_DAT_80012950 + 0x10) = 8;
    FUN_80000dd4(param_1);
    iVar3 = *(int *)(param_1 + 8);
  }
  FUN_80007300(uVar1);
  return 0xffffffff;
}
