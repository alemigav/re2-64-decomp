/* FUN_80164384
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164384  body 0x80164384..0x801643cf  size 76 B
 * body sha256 0596be910ef844d13dc438b5abe29b95c2622b3385acc3664b19d2119ea97873
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80164384.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_80164384(int param_1)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_801643d0();
  }
  else {
    FUN_80164530(param_1);
  }
  FUN_801664d8(param_1);
  return;
}
