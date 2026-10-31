/* FUN_80073018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073018  body 0x80073018..0x80073057  size 67 B
 * body sha256 65603fde82a76da3205ce3deac6eb3011f2effe6ed8694f9d80df3cdaefe4574
 * provider record sha256 ca3faf820b6019a63d1424121c9ce25142b0e3089baed15ec738cf7539368fc1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073018(int param_1)

{
  FUN_8009f320(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
