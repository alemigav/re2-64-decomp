/* FUN_8000ded0
 * image   boot (boot), base 0x80000480
 * address 0x8000ded0  body 0x8000ded0..0x8000df03  size 55 B
 * sha256  08fed13346a57be189d0ca84fa6a117e60c46f8ce542dafefad49a4261c0bfee
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000ded0(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while( true ) {
    piVar1 = piVar2;
    if (piVar1 == (int *)0x0) {
      return;
    }
    if (piVar1 == (int *)param_2) break;
    piVar2 = (int *)*piVar1;
    param_1 = piVar1;
  }
  *param_1 = *piVar1;
  return;
}
