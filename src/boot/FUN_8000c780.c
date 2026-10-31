/* FUN_8000c780
 * image   boot (boot), base 0x80000480
 * address 0x8000c780  body 0x8000c780..0x8000c7d3  size 87 B
 * sha256  f3200a1f4cc414f14f45cff67635bcc3abede5a7e1c01d429f84206ffb08eda0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000c780(void)

{
  _DAT_80012920 = 1;
  osCreateMesgQueue(0x80017710,0x80017700,1);
  osSendMesg(0x80017710,0,0);
  return;
}
