/* FUN_80055fa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80055fa4  body 0x80055fa4..0x80056027  size 135 B
 * sha256  a57e975847b2a464e11a0cd3b85c91a8dc312958e280ea1bf07de63ad3217e86
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80055fa4(int param_1)

{
  (*(code *)(&PTR_FUN_8010dc38)[*(byte *)(param_1 + 5)])(param_1,DAT_800df914,DAT_800df918);
  (*(code *)(&PTR_FUN_8010dc68)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
