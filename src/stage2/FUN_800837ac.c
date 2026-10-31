/* FUN_800837ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837ac  body 0x800837ac..0x800837cf  size 39 B
 * sha256  2f91ec30df6a69a530ef30fc5705a1204b233b3ac96186b0f71764a19503b973
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800837ac(int param_1,uint param_2)

{
  return *(uint *)((param_2 >> 5) * 4 + param_1) & 0x80000000U >> (param_2 & 0x1f);
}
