/* FUN_80031050
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031050  body 0x80031050..0x800310af  size 99 B
 * sha256  5d682644b78d4fa512c5c640843a1df9254226a3a03bc5b178649f323791f6c5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80031050(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_80030fd0();
  iVar2 = FUN_80030fd0(param_1);
  for (iVar1 = iVar1 * 0x100 + iVar2 + -3; -1 < iVar1; iVar1 = iVar1 + -1) {
    FUN_80030fd0(param_1);
  }
  return 1;
}
