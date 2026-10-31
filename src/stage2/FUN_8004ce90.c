/* FUN_8004ce90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce90  body 0x8004ce90..0x8004cec3  size 55 B
 * body sha256 02452f84bac46f1131b9e213505e8aa9ccf3732e69e276c62162539313d89da2
 * provider record sha256 5c13e9d95fd63d34d63a5397cc97218121f70c586775af53f7a4fea11432b2fb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce90(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] | 0x40;
  return;
}
