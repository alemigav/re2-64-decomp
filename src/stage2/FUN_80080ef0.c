/* FUN_80080ef0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080ef0  body 0x80080ef0..0x80081017  size 299 B
 * sha256  800696579c15a1cbe2db6ae881317a9232f6615d4cfd0b21aec5aeddead4270c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80080ef0(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int local_20 [4];
  
  if (*(byte *)(param_1 + 8) < 0x10) {
    if ((*(ushort *)(param_1 + 0x1aa) & 0x4000) == 0) {
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x5000;
    }
    if ((*(ushort *)(param_1 + 0x1aa) & 0x1000) == 0) {
      local_20[0] = (int)*(short *)(param_1 + 0x274);
      local_20[2] = (int)*(short *)(param_1 + 0x276);
      local_20[1] = 0;
      FUN_800653d0(param_1,local_20,0,0);
    }
  }
  if (*(byte *)(param_1 + 8) - 0x10 < 0x10) {
    param_2 = *(undefined4 *)(param_1 + 0x1a4);
    param_3 = *(undefined4 *)(param_1 + 0x218);
  }
  if (((*(ushort *)(param_1 + 0x268) & 0x10) == 0) || ((*(ushort *)(param_1 + 0x268) & 0x20) == 0))
  {
    (*(code *)(&PTR_FUN_8011b6c0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  uVar1 = *(ushort *)(param_1 + 0x268) ^ 0x20;
  *(ushort *)(param_1 + 0x268) = uVar1;
  if ((uVar1 & 1) != 0) {
    FUN_80033680(param_1,0,0);
  }
  if ((*(ushort *)(param_1 + 0x268) & 2) != 0) {
    FUN_80033680(param_1,0,1);
  }
  return;
}
