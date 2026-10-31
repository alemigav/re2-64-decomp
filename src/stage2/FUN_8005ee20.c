/* FUN_8005ee20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ee20  body 0x8005ee20..0x8005ef07  size 235 B
 * sha256  d5c7ce2068fdb743510a0d7bc44412d3b6aca55c7e6da19da40178550d3c20d0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ee20(int param_1)

{
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if ((uint)*(byte *)(param_1 + 0x1e9) % 3 == 1) {
    local_18 = 0x96;
    local_16 = 0x4b0;
    local_14 = 0;
    FUN_80037780(0x31d1200,(int)DAT_800e1196,*(int *)(param_1 + 0x234) + 0x1060,&local_18);
    DAT_80131781 = 1;
  }
  if (*(char *)(param_1 + 0x1e9) == '\x01') {
    FUN_80077adc(0x1000001,*(int *)(param_1 + 0x234) + 0x1044);
    FUN_8005d700(param_1);
  }
  if (*(char *)(param_1 + 0x1e9) == '\v') {
    FUN_80077adc(0x10b0001,*(int *)(param_1 + 0x234) + 0x1044);
  }
  return;
}
