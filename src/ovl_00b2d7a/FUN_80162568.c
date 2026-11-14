/* FUN_80162568
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80162568  body 0x80162568..0x8016259b  size 52 B
 * body sha256 32bc954b089cff4cf3494feea7432256e05f0047085d915ed1b39e612314dc1e
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b2d7a/80162568.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_80162b1c;












void FUN_80162568(int param_1)

{
  (**(code **)(&DAT_80162b1c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
