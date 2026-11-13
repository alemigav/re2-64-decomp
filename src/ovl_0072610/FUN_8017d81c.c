/* FUN_8017d81c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d81c  body 0x8017d81c..0x8017d87f  size 100 B
 * body sha256 8970f803521fe1bfe41b40266fe74943c27fd5ad0dd079dad3b7b88b28c88454
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017d81c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_80185818;












void FUN_8017d81c(void)

{
  int iVar1;
  
  FUN_8017bec8(3);
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    FUN_8017bec8(8);
    FUN_8017bec8(8);
    DAT_80185818 = FUN_8017bec8(8);
  }
  FUN_8017bec8(0xe);
  FUN_8017bbe8(1);
  FUN_8017bec8(0xe);
  return;
}
