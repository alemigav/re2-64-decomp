/* FUN_80083afc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083afc  body 0x80083afc..0x80083c13  size 283 B
 * body sha256 928da296d67e5f953a55188040ff60e5937bb13efb40dfd89d4a3ca3e16c7faf
 * provider record sha256 d2a2586e0b1433b7cf0b59609e63e54b0b04cb1935a6682932a2f35b9f656443
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80083afc(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  
  if ((byte)DAT_800df944[0x16] == DAT_800e8cac) {
    pbVar5 = (byte *)(DAT_800df944 + 0x16);
    pcVar1 = DAT_800df944;
    do {
      pcVar6 = pcVar1 + 0x14;
      if ((*pcVar6 != '\0') &&
         (((pbVar5[-1] == 0xff || (pbVar5[-1] == DAT_800e12d2)) &&
          (iVar2 = FUN_80083d2c(&DAT_800e1158,pcVar6), iVar2 != 0)))) {
        uVar4 = (uint)(byte)pcVar1[0x17];
        goto LAB_80083bdc;
      }
      pbVar5 = pbVar5 + 0x14;
      pcVar1 = pcVar6;
    } while (*pbVar5 == DAT_800e8cac);
  }
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = (uint)(short)DAT_800e8cac;
LAB_80083bdc:
    FUN_80083c14(uVar4);
    uVar3 = 1;
  }
  return uVar3;
}
