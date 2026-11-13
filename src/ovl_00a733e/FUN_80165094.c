/* FUN_80165094
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165094  body 0x80165094..0x801650df  size 76 B
 * body sha256 68b7dce556e4c5c5e8b6d6c1c5c8f078a2681702c583bbd638d158fba531767d
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/80165094.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_80165094(int param_1)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_801650e0();
  }
  else {
    FUN_80165374(param_1);
  }
  FUN_80167c1c(param_1);
  return;
}
