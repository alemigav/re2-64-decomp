/* FUN_8000ab80
 * image   boot (boot), base 0x80000480
 * address 0x8000ab80  body 0x8000ab80..0x8000abff  size 131 B
 * sha256  cb2744235277ddb99961868d020278293b6483af99124082c677f0c673cfe7af
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000ab80(int param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined1 uStack_d;
  
  puVar6 = (uint *)&DAT_80016470;
  iVar5 = 0;
  if (0 < param_1) {
    do {
      iVar5 = iVar5 + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
    } while (iVar5 < param_1);
  }
  uVar3 = *puVar6;
  uVar1 = *(undefined1 *)(puVar6 + 1);
  uVar2 = *(undefined1 *)((int)puVar6 + 5);
  uVar4 = (uVar3 >> 0x10 & 0xc0) >> 4;
  *(char *)((int)param_2 + 3) = (char)uVar4;
  if (uVar4 == 0) {
    uStack_d = (undefined1)uVar3;
    *param_2 = CONCAT11(uVar1,uStack_d);
    *(undefined1 *)(param_2 + 1) = uVar2;
  }
  return;
}
