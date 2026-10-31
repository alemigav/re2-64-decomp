/* FUN_8016250c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016250c  body 0x8016250c..0x80162567  size 95 B
 * sha256  906130bd5fccdd7f05ae7b00e75e393d492d182a96f7ab7122d92e29473ddd4e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016250c(int param_1)

{
  (*(code *)(&PTR_FUN_8016c400)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  if ((*(ushort *)(param_1 + 0x2b6) & 0x180) == 0x100) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  return;
}
