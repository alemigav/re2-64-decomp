/* FUN_80162140
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162140  body 0x80162140..0x8016219f  size 96 B
 * body sha256 42351d50d32e22e5bac57bad5aa56b96a834687ea44fddb1aee9aa83a0595867
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80162140.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166d34;












void FUN_80162140(int param_1)

{
  (*(code *)(&PTR_FUN_80166d34)[*(byte *)(param_1 + 5)])();
  if ((**(uint **)(param_1 + 0x214) & 0x40000) != 0) {
    func_0x80077d18(8,param_1);
  }
  return;
}
