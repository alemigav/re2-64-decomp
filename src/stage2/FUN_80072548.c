/* FUN_80072548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072548  body 0x80072548..0x800725ab  size 103 B
 * sha256  d9d63077a7227f0b54b7eabeaa6ef7a75aa47348a2b2a5f78a8515285244efc5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072548(int param_1)

{
  func_0x80004a6c(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
                  *(undefined2 *)(*(int *)(param_1 + 0x1c) + 2));
  DAT_800e110c = DAT_800e110c | 0x20;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
