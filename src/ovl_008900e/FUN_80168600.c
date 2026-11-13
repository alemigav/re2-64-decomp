/* FUN_80168600
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168600  body 0x80168600..0x80168653  size 84 B
 * body sha256 8cc3b5a9adec56b7721b72a83df075411710ab8362e9f13afa5b4bd158e2ff1f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008900e/80168600.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80168600(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,
                  *(int *)(param_1 + 0x234) + param_6 * 0x178 + 0x38,param_7);
  return;
}
