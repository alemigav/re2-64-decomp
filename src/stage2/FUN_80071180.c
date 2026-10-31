/* FUN_80071180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071180  body 0x80071180..0x800712e7  size 363 B
 * sha256  88c2facb9cfbc4233982b621c99521d943c65a08a411df2eee166a718f467838
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071180(int param_1)

{
  undefined4 *in_v1;
  uint uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = (uint)*(short *)(iVar2 + 4);
  switch(uVar1 >> 8) {
  case 0:
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    goto LAB_80071284;
  case 1:
    in_v1 = (undefined4 *)0x0;
    break;
  case 2:
    in_v1 = DAT_800e13ec;
    break;
  case 3:
    in_v1 = (undefined4 *)(&DAT_800e13e8)[(uVar1 & 0xff) + 2];
    break;
  case 4:
    in_v1 = &DAT_800e18f8 + (uVar1 & 0xff) * 0xda;
  }
  local_20 = in_v1[10];
  local_1c = in_v1[0xb];
  local_18 = in_v1[0xc];
LAB_80071284:
  local_20 = *(short *)(iVar2 + 6) + local_20;
  local_1c = *(short *)(iVar2 + 8) + local_1c;
  local_18 = *(short *)(iVar2 + 10) + local_18;
  FUN_80077adc((uint)*(byte *)(iVar2 + 1) << 0x18 | ((uint)(int)*(short *)(iVar2 + 2) >> 8) << 0x10
               | (int)*(short *)(iVar2 + 2) & 0xffU,&local_20);
  *(int *)(param_1 + 0x1c) = iVar2 + 0xc;
  return 1;
}
