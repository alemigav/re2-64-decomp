/* FUN_8006d5dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d5dc  body 0x8006d5dc..0x8006d627  size 79 B
 * sha256  4ecd025d9c7a67e61d31afc4d82fc93462bed93c94860388b183b062bd09c030
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d5dc(undefined1 *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = DAT_80114f2c;
  uVar1 = *(ushort *)(param_2 * 2 + DAT_80114f2c);
  *(undefined1 **)(param_1 + 0x140) = param_1 + (char)param_1[2] * 0x20 + 0xc0;
  param_1[1] = 1;
  *param_1 = 0;
  param_1[4] = 0xff;
  param_1[8] = 0xff;
  *(uint *)(param_1 + 0x1c) = iVar2 + (uint)uVar1;
  return;
}
