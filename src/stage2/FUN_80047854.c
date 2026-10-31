/* FUN_80047854
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047854  body 0x80047854..0x8004786b  size 27 B
 * body sha256 7ba2d1347814e37dfbe371f735ea1a986b787c38313eb67e0ca777e45156a731
 * provider record sha256 20dcb0f3183a9d3747a9e934494ac0c032f1c630ba7e350d0a85b015ec7abdc6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047854(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  *(undefined2 *)(param_1 + 0x10) = param_4;
  *(undefined2 *)(param_1 + 0x12) = param_5;
  return;
}
