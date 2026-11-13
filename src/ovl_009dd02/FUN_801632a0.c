/* FUN_801632a0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801632a0  body 0x801632a0..0x801632e7  size 72 B
 * body sha256 771fcaef9e2a9e2b61cb607a0de60f02e131c024332a7e1da945dd15f8e1f9bf
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/801632a0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801672a0;












void FUN_801632a0(int param_1)

{
  (*(code *)(&PTR_FUN_801672a0)[*(byte *)(param_1 + 6)])();
  FUN_80162678(param_1);
  return;
}
