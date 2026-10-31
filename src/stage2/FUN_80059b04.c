/* FUN_80059b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059b04  body 0x80059b04..0x80059b5f  size 95 B
 * sha256  5123f34ef44455e6c8441c6368206305063df0f1e7ae44b19f1dd649beac5b1a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059b04(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  (*(code *)(&PTR_FUN_8010dd00)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
