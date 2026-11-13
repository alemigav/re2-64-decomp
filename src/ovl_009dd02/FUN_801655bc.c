/* FUN_801655bc
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801655bc  body 0x801655bc..0x8016561b  size 96 B
 * body sha256 1da991e81167db5d06ceb964c6d858821fe5ae1901a3a06e754085942783ae08
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/801655bc.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_801655bc(int param_1)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    FUN_8016561c();
    if (*(unsigned char *)(param_1 + 5) != '\x01') {
      FUN_80166b98(param_1,10,1);
    }
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
