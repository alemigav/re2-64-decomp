/* FUN_8000f5c0
 * image   boot (boot), base 0x80000480
 * address 0x8000f5c0  body 0x8000f5c0..0x8000fa7b  size 130 B
 * sha256  0e4a943d2122bc93166432b91b37ddff92b3931e6d32175f1b645fee9d2ddf19
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000f5c0(int param_1,undefined4 param_2,byte param_3,int param_4)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_3 - 0x25 < 0x54) {
                    /* WARNING: Could not emulate address calculation at 0x8000f60c */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((param_3 - 0x25) * 4 + -0x7ffee2c8))();
    return;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + 1;
  *(byte *)(param_4 + iVar1) = param_3;
  return;
}
