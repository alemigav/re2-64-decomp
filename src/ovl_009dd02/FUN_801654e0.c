/* FUN_801654e0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801654e0  body 0x801654e0..0x8016554f  size 112 B
 * body sha256 d2539350c452ddd922577b26061f0c7ec80065dae679cc0f734921637115ae7e
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/801654e0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_801654e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(unsigned char *)(param_1 + 6) == '\0') && (*(unsigned char *)(param_1 + 0x2db) == '\0')) {
    *(undefined1 *)(param_1 + 0x2db) = 0x3c;
    FUN_80165310(param_1,2,6);
  }
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
