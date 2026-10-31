/* FUN_80040aa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040aa8  body 0x80040aa8..0x80040bb3  size 271 B
 * sha256  d79c684b7faebc546aa485e0db1ca0eef46b5d0166764132e826097d0b5809a2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040aa8(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_80040bb4(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (*param_1 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  *param_2 = (*param_1 << 0xc) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (param_1[1] << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  param_2[1] = (param_1[1] << 0xc) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (param_1[2] << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  param_2[2] = (param_1[2] << 0xc) / iVar1;
  return;
}
