/* FUN_800793a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800793a4  body 0x800793a4..0x80079417  size 116 B
 * body sha256 dd6fec0c40ff5eb7720c38a26cb11aee7bec4fb6e0c5180d0b444cf1923b44c4
 * recovered byte-exact (imported: closed by the dat:width pass, round 2 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800793a4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;
extern unsigned char DAT_80119e73;
extern unsigned char DAT_80119e74;












void FUN_800793a4(short param_1)

{
  FUN_800b2098((int)((uint)DAT_80119e73 * (int)param_1) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (int)param_1) >> 7 & 0xff,0,1,0);
  return;
}
