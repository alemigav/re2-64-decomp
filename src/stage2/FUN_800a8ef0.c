/* FUN_800a8ef0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8ef0  body 0x800a8ef0..0x800a8f9f  size 179 B
 * sha256  b9e8866a5598ad49496dbf0e63d23c8ff36fe7bdf02cf9aed4ca2c8f6f757922
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a8ef0(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  sVar1 = *param_1;
  do {
    if (sVar1 == -1) {
      return;
    }
    piVar3 = (int *)(param_2 + *(int *)(param_2 + 8));
    iVar2 = *piVar3;
    while (iVar2 != -1) {
      if (*(short *)(piVar3 + 1) == sVar1) goto LAB_800a8f60;
      piVar3 = (int *)((int)piVar3 + *piVar3);
      iVar2 = *piVar3;
    }
    piVar3 = (int *)0x0;
LAB_800a8f60:
    if (piVar3 != (int *)0x0) {
      FUN_800acbc0(*param_1,piVar3 + 2);
    }
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  } while( true );
}
