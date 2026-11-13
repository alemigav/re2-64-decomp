/* FUN_80043868
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043868  body 0x80043868..0x800438d3  size 108 B
 * body sha256 2d422e4dfb8865e5363b316b83f735294e45ef2e896646dee88188e27b12d08f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80043868.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_800efd94;
extern unsigned int DAT_800efd9c;
extern unsigned int DAT_800efda0;












undefined4 FUN_80043868(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efda0 = 0;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x14) {
    param_1 = FUN_80043988(param_1,param_2,0,0);
  }
  return param_1;
}
