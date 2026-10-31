/* FUN_8004d138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d138  body 0x8004d138..0x8004d177  size 67 B
 * sha256  ed8c8df4609659b4aaa540effc90ab43150c70187690f6772ea93c690034a90b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004d138(undefined4 param_1,uint param_2)

{
  if ((param_2 < 5) && ((0 >> (param_2 & 0x1f) & 1U) != 0)) {
    return (&DAT_8010b6c0)[param_2];
  }
  return 0;
}
