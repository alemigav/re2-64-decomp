/* FUN_80164108
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164108  body 0x80164108..0x8016413f  size 56 B
 * body sha256 5bc4a66060513d0e0bd60800aa0ba33abfe162c79f05571582eaec4740e782bf
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80164108.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_80164108(int param_1)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_80164140();
  }
  else {
    FUN_80163604();
  }
  return;
}
