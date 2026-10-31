/* FUN_800b0254
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b0254  body 0x800b0254..0x800b03cb  size 379 B
 * sha256  ab4ab57e0f99729af46caace3cb1eb13a840b2a1b61896b190474a4cb3e1af58
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b0254(int *param_1,uint *param_2,char param_3)

{
  char unaff_10000016;
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  char unaff_s1;
  
  uVar3 = *param_2 >> 0x10;
  if ((*param_2 >> 8 & 0xff) == 0) {
    uVar3 = uVar3 & 0x1f;
    if (uVar3 < 0x10) {
      uVar1 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x180);
    }
    else {
      uVar1 = *(ushort *)((uVar3 - 0x10) * 2 + -0x7feb8050);
    }
  }
  else {
    uVar1 = FUN_800aca08(param_1,uVar3 & 0xff);
  }
  if (*(char *)param_2 == '\0') {
    uVar3 = *(byte *)((int)param_2 + 7) & 0x1f;
    if (uVar3 < 0x10) {
      uVar2 = *(ushort *)((int)param_1 + uVar3 * 2 + 0x180);
    }
    else {
      uVar2 = *(ushort *)((uVar3 - 0x10) * 2 + -0x7feb8050);
    }
  }
  else {
    uVar2 = FUN_800aca08(param_1);
  }
  if (param_3 == '\0') {
    unaff_s1 = uVar1 == uVar2;
  }
  else {
    if (param_3 != '\x01') goto LAB_800b0374;
    unaff_s1 = (int)((uint)uVar1 << 0x10) < (int)((uint)uVar2 << 0x10);
  }
  unaff_10000016 = unaff_s1;
LAB_800b0374:
  if (*(char *)((int)param_2 + 6) != '\0') {
    unaff_s1 = unaff_10000016 == '\0';
  }
  if (unaff_s1 != '\0') {
    param_1[1] = *param_1 + (param_2[1] >> 0x10) * 8;
  }
  return 0;
}
