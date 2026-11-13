/* FUN_8007dae4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dae4  body 0x8007dae4..0x8007db37  size 84 B
 * body sha256 4650c1c17bccb0d132eb4cd48ee4a7615a77c56953ad35cea533b08c52f7ef52
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007dae4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_8007dae4(int param_1)

{
  FUN_8007db38(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if ((*(unsigned char *)(param_1 + 6) != '\0') || (*(unsigned char *)(param_1 + 0x1ea) == '\0')) {
    FUN_80033680(param_1,0,1);
  }
  return;
}
