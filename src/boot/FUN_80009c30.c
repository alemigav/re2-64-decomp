/* FUN_80009c30
 * image   boot (boot), base 0x80000480
 * address 0x80009c30  body 0x80009c30..0x80009c67  size 59 B
 * sha256  7763854c01d6006b189cde4dd8476d916ab055cb969fab5f80e2ea148e10a690
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
short FUN_80009c30(byte *param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = 0;
  sVar2 = 0;
  if (0 < param_2) {
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
      sVar2 = sVar2 + (ushort)bVar1;
    } while (iVar3 < param_2);
  }
  return sVar2;
}
