/* FUN_801664dc
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801664dc  body 0x801664dc..0x8016650f  size 52 B
 * body sha256 96f832b5be430eda6d9a36d94dd07f2d9a12b1caacfdc42fa677e1d732d6524b
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b08a2/801664dc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_801672c8;












void FUN_801664dc(int param_1)

{
  (**(code **)(&DAT_801672c8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
