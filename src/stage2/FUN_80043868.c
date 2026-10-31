/* FUN_80043868
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043868  body 0x80043868..0x800438d3  size 111 B
 * sha256  afc0e20c41fd37b52615be9f1a1ada846504d662a2261f771014b2f59ad0cff1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
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
