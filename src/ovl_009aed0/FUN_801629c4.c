/* FUN_801629c4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801629c4  body 0x801629c4..0x80162a17  size 84 B
 * body sha256 13ddf9c9ca463a3d6afad4a80b0b1b83c2d250d0a4ec35ea9b123f3851fef170
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009aed0/801629c4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801629c4(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,
                  *(int *)(param_1 + 0x234) + param_6 * 0x178 + 0x38,param_7);
  return;
}
