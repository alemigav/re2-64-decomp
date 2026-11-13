/* FUN_8007ef94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ef94  body 0x8007ef94..0x8007efe7  size 84 B
 * body sha256 20b30ff987f8c3a4e29f0d3b3f02a37574fd02b7404f70fed7e0613d4a462b03
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007ef94.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_8007ef94(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),0xa0);
  }
  return;
}
