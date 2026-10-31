/* FUN_80039ba8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039ba8  body 0x80039ba8..0x80039c33  size 143 B
 * sha256  7ec363c1760721d8a866057acfe82672e65dec2b60d21842781f887a32f70c68
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039ba8(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_800ebb94;
  puVar1 = (undefined1 *)(DAT_800ebb94 + 2);
  *(undefined2 *)(DAT_800ebb94 + 0x18) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  *(undefined1 *)(iVar2 + 0x21) = *puVar1;
  iVar3 = DAT_800ebb94;
  *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) | *(ushort *)(iVar2 + 0x14);
  *(undefined1 *)(iVar3 + 0x20) =
       *(undefined1 *)(*(int *)(iVar3 + 0x70) + (uint)*(byte *)(iVar3 + 0x21) * 8 + 2);
  *(char *)(DAT_800ebb94 + 0x1f) = *(char *)(DAT_800ebb94 + 0x1f) + *(char *)(DAT_800ebb94 + 0xb);
  FUN_80039aa0(DAT_800ebb94,
               *(int *)(DAT_800ebb94 + 0x78) + (uint)*(byte *)(DAT_800ebb94 + 0x1f) * 0x18);
  return;
}
