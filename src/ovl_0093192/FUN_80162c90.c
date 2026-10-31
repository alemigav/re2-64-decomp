/* FUN_80162c90
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162c90  body 0x80162c90..0x80162ceb  size 95 B
 * sha256  0b2fd18980209d3bc5e6eadc7ccfe73e033f4e21d3bb0bb52b277868fa8dd91c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80162c90(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
  if (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x25e)) {
    if (*(int *)(param_1 + 0x2c) + -10 < iVar1) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}
