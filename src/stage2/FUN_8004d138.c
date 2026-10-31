/* FUN_8004d138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d138  body 0x8004d138..0x8004d177  size 67 B
 * body sha256 a4f322e9d98d67681c6d7c5179753af61170e37490618c6aed98dac725a7a04e
 * provider record sha256 269c9c23976498181839b5e66a39b82847231ec4be9f4f44d9be81cf7c1c8042
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
