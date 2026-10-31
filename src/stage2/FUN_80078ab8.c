/* FUN_80078ab8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078ab8  body 0x80078ab8..0x80078af7  size 67 B
 * sha256  a393c5f3c6689a66e0ae524a918205829b54bdb217051044264d92e499ce05a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80078ab8(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = &DAT_80119e50;
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 == param_1) {
      return 1;
    }
  } while (*pbVar2 != 0xff);
  return 0;
}
