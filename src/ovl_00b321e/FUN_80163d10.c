/* FUN_80163d10
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163d10  body 0x80163d10..0x80163da3  size 148 B
 * body sha256 4eccf27d260eb945a6e1e4fb75fff039cc2685b55c850bf51bdd47a4a74144d4
 * recovered byte-exact (imported: closed by access type (all undefined2  -> short ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80163d10.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80163d10(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  *(short *)((int)param_1 + 6) = 0x100;
  *(short *)(param_1 + 0x19) = 0;
  *param_1 = *param_1 | 4;
  FUN_801665a0(param_1,1);
  *(short *)(param_1 + 0x78) = 0x30f;
  *(short *)(param_1 + 0x79) = 0;
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x1a) = 0xfc00;
  param_1[0x7a] = 0x8000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
