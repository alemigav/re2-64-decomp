/* FUN_800882d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800882d4  body 0x800882d4..0x80088333  size 99 B
 * sha256  28af216e60c4ab6da2d2666f40b465755066882a35473d11c5270bf1db375a8d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800882d4(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc;
  *(undefined **)(&DAT_8012a0c4 + iVar1) = &DAT_8012a03c;
  *(int *)(&DAT_8012a0c0 + iVar1) = param_1;
  *(undefined4 *)(&DAT_8012a0c8 + iVar1) = 0;
  *(undefined4 *)(&DAT_8012a040 + param_1 * 8) = 2;
  *(undefined **)(&UNK_8012a044 + param_1 * 8) = &DAT_8012a0c0 + iVar1;
  FUN_800879a0();
  return;
}
