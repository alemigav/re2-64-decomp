/* FUN_80166e8c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166e8c  body 0x80166e8c..0x80166edf  size 84 B
 * body sha256 e671e092db5907deee7a1ccfc1685ede2c7ae3eb89b90ef8adf71dcde306669d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008e046/80166e8c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80166e8c(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,
                  *(int *)(param_1 + 0x234) + param_6 * 0x178 + 0x38,param_7);
  return;
}
