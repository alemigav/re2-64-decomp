/* FUN_80042d60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042d60  body 0x80042d60..0x80042dab  size 79 B
 * sha256  8924e1270b56ab7ca0a8bb5694b8738fb57e01cc575dc7ba996b63ba4fe9caa0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80042d60(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  
  puVar6 = (undefined2 *)&DAT_80139a50;
  iVar5 = 2;
  do {
    iVar3 = 2;
    puVar2 = param_1;
    puVar4 = puVar6;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    } while (iVar3 != -1);
    puVar6 = puVar6 + 3;
    iVar5 = iVar5 + -1;
    param_1 = param_1 + 3;
  } while (iVar5 != -1);
  return;
}
