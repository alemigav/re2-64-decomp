/* FUN_801623ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801623ac  body 0x801623ac..0x801623e3  size 56 B
 * body sha256 3b98312762a30dfe2b035d07e0eca3d472eac90a217b09b25ba4fff1c8ba6725
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/801623ac.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;












void FUN_801623ac(int param_1)

{
  if ((((*(ushort *)(param_1 + 0x1aa) & 1) == 0) && (*(unsigned char *)(param_1 + 0x2c3) != '\0')) &&
     ((*(byte *)(param_1 + 0x2bd) & 1) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1060000;
  }
  return;
}
