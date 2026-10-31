/* FUN_8004cfcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cfcc  body 0x8004cfcc..0x8004d02f  size 103 B
 * sha256  41ba0abdea4106b58eb86a7b305b6e2d8d20545d779a6d8499dc37fad34e60d7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004cfcc(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_8010b6c0;
  do {
    uVar1 = FUN_8008b048(4);
    uVar1 = FUN_8004cf30(uVar1);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 4);
  return param_1;
}
