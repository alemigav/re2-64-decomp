/* FUN_8002fd00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fd00  body 0x8002fd00..0x8002fd37  size 59 B
 * sha256  d22906ba21fd1a251c9528d307d532ef73df1aec6b0bfa1b7175a556b2fda6a6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002fd00(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x14) = 0x2e;
  *(undefined4 *)(*param_1 + 0x18) = param_2;
  (**(code **)*param_1)();
  return;
}
