/* FUN_80166210
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166210  body 0x80166210..0x80166297  size 136 B
 * body sha256 fa3623d5dff799226cdbd26b5e8f61c4bc668ce4aa485577ec72e9cfb4e2d438
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80166210.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166f68;












void FUN_80166210(int param_1)

{
  byte bVar2;
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f68)[*(byte *)(param_1 + 6)])();
  bVar2 = *(char *)(param_1 + 0x207) + 1;
  *(byte *)(param_1 + 0x207) = bVar2;
  if ((bVar2 & 1) != 0) {
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
  }
  return;
}
