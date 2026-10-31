/* FUN_8003d144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d144  body 0x8003d144..0x8003d177  size 55 B
 * sha256  47c869e57d11682e864da683834ea4d4cd6f4b4d927f6e60ee0306fa3ced6af6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d144(void)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 0x40;
  iVar1 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 8) = 0;
  *(undefined1 *)(iVar1 + 3) = 0;
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  *(ushort *)(iVar2 + 0x12) = *(ushort *)(iVar2 + 0x12) & 0xfffd;
  return;
}
