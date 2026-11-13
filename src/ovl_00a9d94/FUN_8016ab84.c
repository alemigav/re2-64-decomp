/* FUN_8016ab84
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016ab84  body 0x8016ab84..0x8016abe7  size 100 B
 * body sha256 a901cc2b18f07ee567f62ed3cae2eb5e8607af22acdb057b3f744e113ef74c86
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016ab84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_LAB_8016c518;












void FUN_8016ab84(int param_1,undefined4 param_2)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
    (*(code *)(&PTR_LAB_8016c518)[*(byte *)(param_1 + 0x2c4)])();
    func_0x80066288(param_1,param_2);
  }
  return;
}
