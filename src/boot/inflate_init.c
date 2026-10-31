/* inflate_init
 * image   boot (boot), base 0x80000480
 * address 0x80004550  body 0x80004550..0x80004593  size 71 B
 * sha256  9c8b1cc0304a4bdf460772b4e4d2e1792c000dd23b916f3fbd6387081cc45334
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int inflate_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_800013b0(param_2);
  uVar1 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return param_1;
}
