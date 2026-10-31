/* FUN_800a2e40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2e40  body 0x800a2e40..0x800a2f07  size 203 B
 * sha256  2b271d4d2e9baaaff770ec54b66ba89fe9559c4e923b5cfe28c0ad7f433c6b94
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2e40(void)

{
  uint uVar1;
  
  uVar1 = (uint)*_DAT_80143f54;
  if (uVar1 != 0) {
    _DAT_80143c60 = 2;
    _DAT_80143c6c = 0xd0;
    _DAT_80143c70 = &DAT_800b2700;
    _DAT_80143c74 = 0x1000;
    _DAT_80143c78 = &DAT_80136b50;
    _DAT_80143c64 = 0;
    _DAT_80143c68 = entry;
    _DAT_80143c7c = 0x800;
    _DAT_80143c90 = _DAT_80143f50;
    _DAT_80143c94 = uVar1;
    func_0x8000efa0(_DAT_80143f50,uVar1 * 0xa10);
    (*_DAT_80143ff0)(&DAT_80143c60);
    DAT_80143f4d = 1;
  }
  return;
}
