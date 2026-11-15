/* FUN_8009c594
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009c594  body 0x8009c594..0x8009c65f  size 204 B
 * body sha256 4f3c0c98557357dd382f9d4dd2d6277428dba3eb02d4379de655e71359fb5a57
 * recovered byte-exact (imported: closed by the dat:width pass, round 7 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8009c594.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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
