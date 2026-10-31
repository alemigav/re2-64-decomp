/* FUN_8004dbf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004dbf8  body 0x8004dbf8..0x8004dcb7  size 195 B
 * sha256  38dc53db5cf12a17f500a8ec0fcc26a5167929d4ea73361e777d16c050bd4d7a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004dbf8(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar6;
  uint uVar5;
  
  FUN_8004da40(param_1,param_1 + 10);
  uVar4 = 0x8000;
  *(undefined1 *)((int)param_1 + 0xd) = 0xff;
  puVar3 = &DAT_800e13e8;
  uVar5 = 0;
  uVar6 = 0;
  if (DAT_800df93c != &DAT_800e13e8) {
    do {
      puVar2 = (uint *)*puVar3;
      if (((param_1 != puVar2) && ((*puVar2 & 1) != 0)) &&
         (iVar1 = FUN_8004d3a0(puVar2,param_1), iVar1 != 0)) {
        uVar5 = uVar5 | uVar4;
      }
      uVar6 = (undefined2)uVar5;
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 >> 1;
    } while (puVar3 != DAT_800df93c);
  }
  *(undefined2 *)((int)param_1 + 0xe) = uVar6;
  return;
}
