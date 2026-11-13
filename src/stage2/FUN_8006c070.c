/* FUN_8006c070
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006c070  body 0x8006c070..0x8006c0d3  size 100 B
 * body sha256 e80296eabaefe81c49518a33ba77027db2b12a50c15ad84c2b39f434d62fb41e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006c070.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_80112784;
extern unsigned int DAT_80112788;
extern unsigned int DAT_80112a24;












void FUN_8006c070(int param_1)

{
  DAT_80112784 = param_1;
  if (param_1 == 0) {
    for (; DAT_80112788 != 0; DAT_80112788 = DAT_80112788 + -1) {
      func_0x8000cb60(&DAT_80112a24,0,0);
    }
  }
  return;
}
