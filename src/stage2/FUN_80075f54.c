/* FUN_80075f54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075f54  body 0x80075f54..0x80075fbf  size 111 B
 * sha256  af58112c19ef437842b4fd2f0629361da98d851662db23386cdbce3c4daadfc5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075f54(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar4 = (undefined4 *)&DAT_8011a37c;
  do {
    uVar2 = 0;
    *(undefined1 *)(puVar4 + 10) = 0;
    *(undefined2 *)((int)puVar4 + 2) = 0;
    *(undefined2 *)puVar4 = 0;
    iVar3 = iVar5;
    do {
      iVar1 = uVar2 + iVar5;
      uVar2 = uVar2 + 1;
      *(undefined4 *)((int)&DAT_8011a380 + iVar3) = 0xffffffff;
      *(undefined4 *)((int)&DAT_8011a390 + iVar3) = 0;
      (&DAT_8011a3a0)[iVar1] = 0;
      iVar3 = iVar3 + 4;
    } while (uVar2 < 4);
    puVar4 = puVar4 + 0xf;
    iVar5 = iVar5 + 0x3c;
  } while (puVar4 < &DAT_8011a700);
  return;
}
