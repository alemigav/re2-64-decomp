/* FUN_800a9540
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9540  body 0x800a9540..0x800a9577  size 59 B
 * body sha256 9068a8301df3e6cd026bc38766861d0a65f693020e2159a583786f475fcbd4b0
 * provider record sha256 a73ec8a240c1ac28e7793ca90372d47eb36dbe991ec6538e72a20a9aef0b4206
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a9540(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = 0;
  if (DAT_80147a58 != 0) {
    puVar2 = &DAT_801481e0;
    do {
      *puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x18;
    } while (iVar1 < (int)(uint)DAT_80147a58);
  }
  return;
}
