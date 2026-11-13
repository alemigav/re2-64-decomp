extern unsigned int DAT_80184b20;
extern unsigned int DAT_80184b24;
extern unsigned int DAT_80184b28;












void  entry(void)

{
  DAT_80184b20 = 0;
  DAT_80184b28 = 0;
  DAT_80184b24 = FUN_80180070(0x1000);
  return;
}
