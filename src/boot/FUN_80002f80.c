/* FUN_80002f80
 * image   boot (boot), base 0x80000480
 * address 0x80002f80  body 0x80002f80..0x80002fe7  size 107 B
 * sha256  8e3f0624cb5b34bb46286b9ba7bbf8f1a045189d537b6a7af948b197bc6e954e
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
