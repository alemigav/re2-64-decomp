/* FUN_80073af4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073af4  body 0x80073af4..0x80073cf7  size 519 B
 * sha256  c8f8874b5dcb2681d1e1fa7d63345e922c316271c7d47abe90b24bd9107d02dd
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073af4(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_800e13b0 != 0) {
    return 0;
  }
  if ((((DAT_800e110c & 0x90000000) == 0x90000000) && ((*DAT_800e13ec & 1) != 0)) &&
     ((DAT_800e13ec[0xae] & 0x20000000) != 0)) {
    iVar2 = 8;
  }
  else {
    if (((*(byte *)(param_1 + 0xf) & 0x80) == 0) ||
       (iVar2 = FUN_800837ac(&DAT_800e8ec0,*(byte *)(param_1 + 0xf) & 0x3f), iVar2 != 0)) {
      DAT_800dfb58 = param_1;
      DAT_800e1110 = DAT_800e1110 | 0xff000000;
      DAT_80131780 = 1;
      return 0;
    }
    bVar1 = *(byte *)(param_1 + 0x10);
    uVar3 = (uint)bVar1;
    if (uVar3 == 0xfe) {
      FUN_8004ac04(0,0x100,10,0xff000000);
      FUN_80077adc(0x2260000,0);
LAB_80073c60:
      FUN_80083758(&DAT_800e8ec0,*(byte *)(param_1 + 0xf) & 0x3f);
      return 0;
    }
    if (uVar3 == 0xff) {
      FUN_80077adc(0x2160000,0);
      iVar2 = 0xb;
    }
    else {
      iVar2 = FUN_8008c51c(uVar3);
      if (-1 < iVar2) {
        DAT_8010b297 = bVar1;
        FUN_8004ac04(0,0x100,5,0xff000000);
        FUN_80077adc(0x2250000,0);
        DAT_800e8924 = FUN_80073cf8;
        DAT_800e861d = (char)iVar2 + '\x01';
        goto LAB_80073c60;
      }
      FUN_80077adc(0x2160000,0);
      iVar2 = uVar3 - 0x4c;
    }
  }
  FUN_8004ac04(0,0x100,iVar2,0xff000000);
  return 0;
}
