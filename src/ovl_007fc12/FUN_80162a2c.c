/* FUN_80162a2c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162a2c  body 0x80162a2c..0x80162a63  size 56 B
 * body sha256 202c86a0d7360ba3fe64ed16831a1203bcb6e7e35e084654ecdc58b12c49936b
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007fc12/80162a2c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_8016e174;












void FUN_80162a2c(int param_1)

{
  (*(code *)(&PTR_FUN_8016e174)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
