/* FUN_800a597c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a597c  body 0x800a597c..0x800a59cf  size 87 B
 * sha256  ddac1232091ab0509c004bd405368cb0b6cbe8aec45f86abf8ec051dfcb653c0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a597c(uint param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(_DAT_80143f0c + (param_1 & 0xffff) * 0x68);
  puVar1[0x5c] = 0;
  *(undefined4 *)(puVar1 + 0x50) = 0;
  *(undefined4 *)(puVar1 + 0x58) = 0;
  *(undefined4 *)(puVar1 + 0x4c) = 0;
  *(undefined4 *)(puVar1 + 0x54) = 0x3f800000;
  *puVar1 = 1;
  *(undefined2 *)(puVar1 + 0x48) = *(undefined2 *)(puVar1 + 0x20);
  return;
}
