/* FUN_800a8fa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8fa0  body 0x800a8fa0..0x800a9053  size 183 B
 * sha256  0d6d53218634d7d8f35f71f028fe574c6c00f59f4a56163754d6efac69d5c019
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a8fa0(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  sVar1 = *param_1;
  do {
    if (sVar1 == -1) {
      return;
    }
    piVar3 = (int *)(param_2 + *(int *)(param_2 + 0xc));
    iVar2 = *piVar3;
    while (iVar2 != -1) {
      if (*(short *)(piVar3 + 1) == sVar1) goto LAB_800a9010;
      piVar3 = (int *)((int)piVar3 + *piVar3);
      iVar2 = *piVar3;
    }
    piVar3 = (int *)0x0;
LAB_800a9010:
    if (piVar3 != (int *)0x0) {
      FUN_800ace1c(*param_1,piVar3 + 3,*(undefined2 *)((int)piVar3 + 10));
    }
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  } while( true );
}
