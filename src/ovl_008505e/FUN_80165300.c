/* FUN_80165300
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165300  body 0x80165300..0x80165387  size 136 B
 * body sha256 63d45165964b9b14771f428e8f7ebf7133153cb46826b1c1dbd33577aa167443
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80165300.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166e7c;












void FUN_80165300(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166e7c)[*(byte *)(param_1 + 6)])();
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,5);
  return;
}
