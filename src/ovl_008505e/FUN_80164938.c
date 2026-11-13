/* FUN_80164938
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164938  body 0x80164938..0x801649fb  size 196 B
 * body sha256 5e96abb16bb6e5f41e56d714a8f5b1f02c3546be07d1cfaa0ce2bc13181d16e9
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80164938.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164938(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x2c8) = 1;
  iVar1 = FUN_80163060();
  if (iVar1 < 0) {
    *(undefined2 *)(param_1 + 6) = 0x200;
    *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  if ((*(uint *)(param_1 + 0x1ac) & 1) != 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
    *(undefined4 *)(param_1 + 0x1e8) = 0x16000f00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x270) = 1;
    *(short *)(param_1 + 0x1e0) = -(*(short *)(param_1 + 0x1e0) >> 1);
  }
  return;
}
