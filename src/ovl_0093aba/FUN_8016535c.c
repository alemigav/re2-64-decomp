/* FUN_8016535c
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x8016535c  body 0x8016535c..0x8016538f  size 52 B
 * body sha256 9eb61d4334b57343280070293543454537c611148b7344b3a1a68c2bd904265e
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0093aba/8016535c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_8016554c;












void FUN_8016535c(int param_1)

{
  (**(code **)(&DAT_8016554c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
