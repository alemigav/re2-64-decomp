/* FUN_800404d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800404d8  body 0x800404d8..0x80040523  size 79 B
 * body sha256 f55260c5a07d81afcc7c9f83b3fc66e1d17018d9aa4184e353f7c6fb09b6e4ff
 * provider record sha256 be09e0365f4fef0cdff98c725a89b525a7471961a8d74f4896f6fe5020608d54
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800404d8(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  puVar2 = DAT_800ebb94;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  FUN_80038a20(*(ushort *)(puVar2 + 0x3a) | 0x14000000,0,&DAT_800e9028,puVar2 + 0x34);
  return;
}
