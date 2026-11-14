/* FUN_80168448
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168448  body 0x80168448..0x8016847b  size 52 B
 * body sha256 5939f89d9eb5aaaf8e13c26a073a84e883ace1f098adad96f24d5b18ce8d0a44
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008900e/80168448.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_80168d4c;












void FUN_80168448(int param_1)

{
  (**(code **)(&DAT_80168d4c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
