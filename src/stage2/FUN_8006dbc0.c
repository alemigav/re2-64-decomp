/* FUN_8006dbc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dbc0  body 0x8006dbc0..0x8006dbf3  size 55 B
 * sha256  0301a21cefec817affbf65ae7590d49f2c96e6a50309a0f47826655070a120a2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006dbc0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar3 + 1);
  uVar2 = *(undefined1 *)(iVar3 + 3);
  *(int *)(param_1 + 0x1c) = iVar3 + 4;
  FUN_8006d628(uVar1,uVar2);
  return 1;
}
