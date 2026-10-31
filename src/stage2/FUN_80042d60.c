/* FUN_80042d60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042d60  body 0x80042d60..0x80042dab  size 79 B
 * body sha256 d457c0b1fd3e0199d659b3a353b23fc9b33fe381e8818c3a52eb34f3cde04c7d
 * provider record sha256 556f50076bac176b4a612b9b7b99bd8342a6805d8304ece8287ba4972ff6e305
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
