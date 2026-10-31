/* FUN_8006da14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006da14  body 0x8006da14..0x8006daff  size 239 B
 * sha256  f78d2c0ef81cc7ac688fa5f1303f249bcf2193563b16d846988c791fae48e4d9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006da14(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = &DAT_80113ad0;
  do {
    if (puVar2[1] != '\0') {
      while( true ) {
        do {
          FUN_8006d100(**(undefined1 **)(puVar2 + 0x1c));
          iVar1 = (*(code *)(&PTR_LAB_80113898)[**(byte **)(puVar2 + 0x1c)])(puVar2);
        } while (iVar1 == 1);
        if ((iVar1 == 2) || ((char)puVar2[(char)puVar2[2] + 4] < '\0')) break;
        iVar1 = *(int *)(puVar2 + 0x140);
        *(int *)(puVar2 + 0x140) = iVar1 + -4;
        *(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(iVar1 + -4);
        puVar2[(char)puVar2[2] + 4] = puVar2[(char)puVar2[2] + 4] + -1;
      }
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 0x174;
  } while (uVar3 < 10);
  FUN_8006d334();
  FUN_8006d384();
  return;
}
