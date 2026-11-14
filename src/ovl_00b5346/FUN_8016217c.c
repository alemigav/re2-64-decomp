/* FUN_8016217c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x8016217c  body 0x8016217c..0x801621f7  size 124 B
 * body sha256 8e0967b38d5bd9c8be2de9f84cd335d487b400633a7c26b8f93bbeaede9b15c8
 * recovered byte-exact (imported: closed by the symbol:addr pass after localtype+cast (31 of 31) (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b5346/8016217c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;
typedef unsigned int undefined4;
extern unsigned char D_800e8d00[];












void FUN_8016217c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x800837ac((u32)D_800e8d00,0x1f);
  if (iVar1 == 0) {
    if (*(unsigned char *)(param_1 + 6) == '\0') {
      FUN_801621f8(param_1,param_2,param_3);
    }
    else {
      FUN_80162408(param_1,param_2,param_3);
    }
  }
  return;
}
