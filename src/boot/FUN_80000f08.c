/* FUN_80000f08
 * image   boot (boot), base 0x80000480
 * address 0x80000f08  body 0x80000f08..0x80000f4f  size 75 B
 * sha256  fc293c3d6fbd0fdcf72522301d58d20cbd94b884c7d6c841f31124936f38c5ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80000f08(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = ((int *)*param_1)[1];
  piVar4 = (int *)*param_1;
  piVar2 = param_1;
  while (piVar1 = piVar4, param_2[1] <= iVar3) {
    piVar4 = (int *)*piVar1;
    iVar3 = piVar4[1];
    piVar2 = piVar1;
  }
  *param_2 = *piVar2;
  *piVar2 = (int)param_2;
  param_2[2] = (int)param_1;
  return;
}
