/* FUN_80165c5c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165c5c  body 0x80165c5c..0x80165cd7  size 124 B
 * body sha256 3efcbdb88d1e3f53143226520968db5321bd44185ce374f94c334f43df94cc68
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80165c5c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166f48;












void FUN_80165c5c(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f48)[*(byte *)(param_1 + 6)])();
  FUN_80166980(param_1,3,0);
  FUN_80166980(param_1,2,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,2,(uVar1 & 1) + 1);
  return;
}
