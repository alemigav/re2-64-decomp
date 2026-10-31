/* FUN_80072d04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072d04  body 0x80072d04..0x80072d63  size 99 B
 * body sha256 fdc0a05049748343d189e3f850b9fd91b077ef051a318beae86d374c490de5f0
 * provider record sha256 2cbbe4a84d8b7de31c52881283c27e08aac10df9f9f116f39742c15a60ad9183
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072d04(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined2 *)
   (DAT_800e8cac * 0x28 + *(int *)(DAT_800df92c + 0x2c) + (uint)*(byte *)(iVar1 + 1) * 2 + 0x22) =
       *(undefined2 *)(iVar1 + 2);
  *(int *)(param_1 + 0x1c) = iVar1 + 4;
  return 1;
}
