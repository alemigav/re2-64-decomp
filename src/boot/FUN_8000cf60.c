/* FUN_8000cf60
 * image   boot (boot), base 0x80000480
 * address 0x8000cf60  body 0x8000cf60..0x8000cfb3  size 87 B
 * sha256  a3aca0cb16d2fc5a3b26078e9c1246bd9ff18d14ffab4bb555ce43fd9d34464c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cf60(void)

{
  _DAT_80012930 = 1;
  osCreateMesgQueue(0x800177c0,0x800177b0,1);
  osSendMesg(0x800177c0,0,0);
  return;
}
