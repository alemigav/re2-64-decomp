/* FUN_80009c30
 * image   boot (boot), base 0x80000480
 * address 0x80009c30  body 0x80009c30..0x80009c67  size 59 B
 * body sha256 d69fac0f0a4f782a417b0c6a82697dc7dee92228fa40367149f0c1974bd88826
 * provider record sha256 432964ee54b0c21ddfc9be61fc5bd53910f462977b2ec60a4de25d564cec7415
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
