/* FUN_800404d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800404d8  body 0x800404d8..0x80040523  size 79 B
 * sha256  47a78882bc5372fed2b13d8ada76d06f114f0d74942df9f3a1467eb659068c59
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
