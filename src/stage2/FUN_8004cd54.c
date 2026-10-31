/* FUN_8004cd54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd54  body 0x8004cd54..0x8004cd87  size 55 B
 * sha256  3dfef0209fdffba73b1beb76bb4a4c2294d7df09873851b3220c2129a06129a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cd54(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_8010b4e0 + param_1 * 0x1c8) = param_2;
  (&DAT_8010b328)[param_1 * 0xe4] = 2;
  return;
}
