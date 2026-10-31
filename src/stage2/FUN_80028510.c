/* FUN_80028510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028510  body 0x80028510..0x8002857b  size 111 B
 * sha256  03d5efef6dbead8c385175bd35c25ccaffea17fc27fd842d2888bdc673502ce7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028510(int *param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0xfe) {
    *(undefined4 *)(param_1[0x5d] + 0xc) = param_3;
  }
  else if (param_2 - 0xe0U < 0x10) {
    *(undefined4 *)(param_1[0x5d] + (param_2 - 0xe0U) * 4 + 0x10) = param_3;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x3c;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
  }
  return;
}
