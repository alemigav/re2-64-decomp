/* FUN_801665a0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801665a0  body 0x801665a0..0x801665e3  size 68 B
 * body sha256 737b3d6e2ed5724de645842651650b05bf91481ea950c4f91030b3d11d08ec67
 * recovered byte-exact (imported: closed by access type (all undefined2  -> short ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/801665a0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












void FUN_801665a0(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(short *)(param_1 + 0x134) = 0xfce0;
    *(short *)(param_1 + 0x13a) = 1000;
    *(short *)(param_1 + 300) = 800;
    *(short *)(param_1 + 0x12e) = 0x578;
    return;
  }
  *(short *)(param_1 + 0x13a) = 2000;
  *(short *)(param_1 + 0x134) = 0;
  *(short *)(param_1 + 300) = 4;
  *(short *)(param_1 + 0x12e) = 4;
  return;
}
