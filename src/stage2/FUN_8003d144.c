/* FUN_8003d144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d144  body 0x8003d144..0x8003d177  size 55 B
 * body sha256 3ad3c5bca23fe62745c660b475020d942dfdbdeec4a896f222f53e3cf1ee1303
 * provider record sha256 639079f5caac12293c6c836550067c6770b3c9829a37d75447086fb141f1fe4a
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
