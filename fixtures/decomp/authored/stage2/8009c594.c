typedef unsigned char undefined1;
typedef unsigned int uint;
extern short DAT_800e9184;
extern unsigned char DAT_80119e70;
extern unsigned char DAT_8013272c;
extern short DAT_80132738;
extern short DAT_8013273a;
extern short DAT_8013273c;
extern short DAT_8013273e;
extern unsigned int DAT_80132740;
extern unsigned int DAT_80132744;
extern unsigned int DAT_80132748;












void FUN_8009c594(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_80132748;
  uVar3 = 0;
  do {
    if ((puVar2[1] & 0x10) != 0) {
      *puVar2 = 0;
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 0xc;
  } while (uVar3 < (uint)(int)DAT_80132738);
  if (((DAT_8013272c == '\x01') && (DAT_80132744 = 0, DAT_80119e70 == '\0')) &&
     ((iVar1 = FUN_8002767c(0), iVar1 != 0 || (DAT_800e9184 == 0x7fff)))) {
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_8013272c = '\x02';
    DAT_8013273a = 0x5a;
    DAT_8013273c = DAT_8013273e;
  }
  return;
}
