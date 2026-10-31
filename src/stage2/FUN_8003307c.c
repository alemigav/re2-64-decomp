/* FUN_8003307c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003307c  body 0x8003307c..0x80033143  size 203 B
 * sha256  2bb6b0b1c797137eccea76a741ad365ba2ed8d510e0a94e08a8c800894300eaf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8003307c(int param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 local_28;
  undefined2 local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  if (param_4 == (undefined4 *)0x0) {
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = *param_4;
    local_24 = *(undefined2 *)(param_4 + 1);
  }
  FUN_80042824(param_1,&local_28,&local_20);
  local_20 = local_20 + *(int *)(param_1 + 0x14);
  local_1c = local_1c + *(int *)(param_1 + 0x18);
  local_18 = local_18 + *(int *)(param_1 + 0x1c);
  uVar1 = FUN_80040bb4((local_20 - *param_2) * (local_20 - *param_2) +
                       (local_18 - param_2[2]) * (local_18 - param_2[2]));
  return uVar1 < param_3;
}
