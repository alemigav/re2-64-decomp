/* FUN_80078ab8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078ab8  body 0x80078ab8..0x80078af7  size 67 B
 * body sha256 cdad6d194a6a412612ef20fe3128a23e14d0faac55611f1b404019bb597916fb
 * provider record sha256 8725011ba42cc3cec90c381bdfd19046cc4c9f2223e21febabf7f1620f24d56e
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
