/* FUN_800879d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800879d0  body 0x800879d0..0x80087a27  size 91 B
 * body sha256 199edfbd6258c4fbf7d70f851a697f48b1a9d562846569b58c5c7ece75bd17fa
 * provider record sha256 354decd5bcb8d10e0af565bd06dd61eb68e531b67c9f427efc128019c5035cd1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800879d0(undefined4 *param_1)

{
  func_0x800066f0(0x8013a2f0);
  osRecvMesg(0x8013a2f0,0,1);
  osSendMesg(param_1[1],*param_1,0);
  return;
}
