/* FUN_80002f80
 * image   boot (boot), base 0x80000480
 * address 0x80002f80  body 0x80002f80..0x80002fe7  size 107 B
 * body sha256 47c5918293b01aa18e9f06d6d7d305886de9d1d018677190ef76bd37fd158e5e
 * provider record sha256 d6dada31be1e8a3c3929708f26e69d11e321973c9faaeaeebe627e1407bed2e6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80002f80(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_10 [8];
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar1 = 0;
    if ((*(undefined4 **)(param_1 + 0x1c))[3] != 0) {
      uVar1 = 7;
    }
    **(undefined4 **)(param_1 + 0x1c) = uVar1;
    FUN_80001510(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x14),param_1,auStack_10);
    uVar1 = 0;
  }
  return uVar1;
}
