/* FUN_800040d4
 * image   boot (boot), base 0x80000480
 * address 0x800040d4  body 0x800040d4..0x800040fb  size 43 B
 * sha256  20517c9714a9b9ac6c34d996047b6542f211fdb142f186d4483a647912e14694
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800040d4(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 - param_2;
  return (iVar1 - param_2) * 8 + -0x7ffec140;
}
