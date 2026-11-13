/* FUN_80035dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035dbc  body 0x80035dbc..0x80035de7  size 44 B
 * body sha256 6fb16639e6422adc28c0e9b70143130912ed75128c41557396ccecfb803773fc
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80035dbc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_800eb78c;












void FUN_80035dbc(int param_1,undefined4 param_2)

{
  FUN_80036008(param_1,*(int *)(param_1 + 0x234) + 0x2f0,&DAT_800eb78c,param_2);
  return;
}
