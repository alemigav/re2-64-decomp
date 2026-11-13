/* FUN_800ac888
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac888  body 0x800ac888..0x800ac8a7  size 32 B
 * body sha256 0b882375aacfd23526916d971ecd424c688897c23343f6b91a164ee39512394e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800ac888.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












undefined2 FUN_800ac888(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_800ac394(param_1,param_1 + 0xc4);
  return uVar1;
}
