/* FUN_80078af8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078af8  body 0x80078af8..0x80078b37  size 67 B
 * sha256  00a8222d1459bf818b4ea952790bfb6aabc77d74294ff32d7c75f1dcebc41ffc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80078af8(uint param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = &DAT_80119e5c;
  do {
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 == param_1) {
      return 1;
    }
  } while (*pbVar2 != 0xff);
  return 0;
}
