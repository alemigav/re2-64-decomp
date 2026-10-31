/* FUN_80070474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070474  body 0x80070474..0x800704df  size 111 B
 * sha256  b16774d3f6ae49c386a0c626941d504adbdec37606433ef0acd711795f9a72a2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80070474(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800704e0(*(undefined4 *)(param_1 + 0x154),
                       *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2));
  FUN_8006e838(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),uVar1,
               (int)(short)(&DAT_800e8c78)[*(byte *)(*(int *)(param_1 + 0x1c) + 3)]);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
