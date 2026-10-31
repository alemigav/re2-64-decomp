/* FUN_800048b0
 * image   boot (boot), base 0x80000480
 * address 0x800048b0  body 0x800048b0..0x800048df  size 51 B
 * sha256  806c7e6077ec9a9408a1d84aa6594271e9f743249b330fb24884205043c86431
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800048b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x8000 - *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0x8000;
    iVar1 = *(int *)(param_1 + 0x50) + iVar2;
    *(int *)(param_1 + 0x50) = iVar1;
    *(int *)(param_1 + 0xc) = iVar1;
  }
  return iVar2;
}
