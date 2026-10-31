/* FUN_80088334
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088334  body 0x80088334..0x8008836b  size 59 B
 * sha256  5f72ed7b7a095008a227376e1c7c875fef6e10b09c44bdfd2b5076cd126adfd6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088334(int param_1)

{
  *(undefined4 *)(&DAT_8012a040 + param_1 * 8) = 4;
  *(int *)(&UNK_8012a044 + param_1 * 8) = param_1;
  FUN_800879a0();
  return;
}
