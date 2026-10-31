/* FUN_80033024
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033024  body 0x80033024..0x8003307b  size 91 B
 * sha256  69a9af73f50b6236332f335159dbad3a6d6cebb9c7b93ba4787ecc89c64a2dd4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033024(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = FUN_80040bb4((*param_1 - *param_2) * (*param_1 - *param_2) +
                       (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]));
  return uVar1 < param_3;
}
