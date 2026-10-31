/* FUN_8008d090
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d090  body 0x8008d090..0x8008d15f  size 211 B
 * sha256  a3cd122283e046b9934689ba719606cb1ac6948033cf1c577b265668bcfd911f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d090(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = (&DAT_8012ffa8)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa0 * 4] * 8];
  iVar2 = FUN_8008c51c(*(&PTR_DAT_8012ffac)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa0 * 4] * 2]
                      );
  iVar2 = iVar2 * 4;
  uVar3 = (uint)(byte)(&DAT_800e8ec9)[iVar2];
  if (bVar1 < uVar3) {
    (&DAT_800e8ec9)[iVar2] = (&DAT_800e8ec9)[iVar2] - bVar1;
    uVar3 = (uint)bVar1;
  }
  else {
    (&DAT_800e8ec8)[iVar2] = 0;
    FUN_8008c568();
  }
  FUN_8008c33c((uint)DAT_8012bfa0,(byte)(&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] + uVar3);
  return;
}
