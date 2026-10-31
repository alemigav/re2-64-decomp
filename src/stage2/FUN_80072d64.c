/* FUN_80072d64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072d64  body 0x80072d64..0x80072ddb  size 123 B
 * body sha256 d925f8be906b2edfc0a544b570182d9ae2fbf3b2a73e22c6515add0625e121ef
 * provider record sha256 8d34da3cd21a1c9282b50bd860085e660473c6393c1f6856431a38357ae17775
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072d64(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  puVar1 = (undefined1 *)
           (*(int *)(DAT_800df92c + 0x2c) + DAT_800e8cac * 0x28 + (uint)*(byte *)(iVar2 + 1) * 3 + 4
           );
  *puVar1 = *(undefined1 *)(iVar2 + 2);
  puVar1[1] = *(undefined1 *)(iVar2 + 3);
  puVar1[2] = *(undefined1 *)(iVar2 + 4);
  *(int *)(param_1 + 0x1c) = iVar2 + 6;
  return 1;
}
