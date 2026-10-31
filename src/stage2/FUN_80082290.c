/* FUN_80082290
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082290  body 0x80082290..0x80082307  size 123 B
 * body sha256 845c4f6525bc8875dca566245cfb9b70be9c6554994ae71c944874ec12c1a007
 * provider record sha256 7ce1d50bc1e1132edc71db9be6bbbd314f5b45148f7a806620ca4e0b508eca0a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined1 * FUN_80082290(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  if (param_1 == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    iVar2 = FUN_80082388(param_1);
    puVar1 = (undefined1 *)FUN_8008b0ec(iVar2 + 1);
    iVar5 = 0;
    if (-1 < iVar2) {
      puVar4 = puVar1;
      do {
        puVar3 = (undefined1 *)(param_1 + iVar5);
        iVar5 = iVar5 + 1;
        *puVar4 = *puVar3;
        puVar4 = puVar1 + iVar5;
      } while (iVar5 <= iVar2);
    }
  }
  return puVar1;
}
