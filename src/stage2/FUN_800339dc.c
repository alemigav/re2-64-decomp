/* FUN_800339dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800339dc  body 0x800339dc..0x80033a5f  size 135 B
 * sha256  a615eb624d7cf253e5c282c72875912700a2c0e269ccba900ae5b94643c752fd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800339dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  
  puVar1 = (undefined2 *)&UNK_800dfc14;
  iVar3 = 0x32;
  if (DAT_800dfc22 == '\0') {
LAB_80033a08:
    if (iVar3 != 0) {
      *param_1 = puVar1;
      *(undefined1 *)(puVar1 + 7) = 5;
      *(undefined4 *)(puVar1 + 10) = param_5;
      if (param_4 == 0) {
        param_4 = 0x80808000;
      }
      else {
        param_4 = *(byte *)((int)puVar1 + 0x1b) | param_4;
      }
      *(uint *)(puVar1 + 0xc) = param_4;
      puVar1[1] = (short)((uint)param_2 >> 0x10);
      *puVar1 = (short)param_2;
      puVar1[2] = (short)param_3;
      puVar1[3] = (short)((uint)param_3 >> 0x10);
      return;
    }
  }
  else {
    puVar2 = puVar1;
    for (iVar3 = 0x31; puVar1 = puVar2 + 0x34, iVar3 != 0; iVar3 = iVar3 + -1) {
      if (*(char *)(puVar2 + 0x3b) == '\0') goto LAB_80033a08;
      puVar2 = puVar1;
    }
  }
  *param_1 = 0;
  return;
}
