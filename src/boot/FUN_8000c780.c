/* FUN_8000c780
 * image   boot (boot), base 0x80000480
 * address 0x8000c780  body 0x8000c780..0x8000c7d3  size 87 B
 * body sha256 42cf60798ded1258a1544084051d7f8b087c6a0f89c5a97ea334456226c17c93
 * provider record sha256 48274d103a3b683193345bb661d61c9de6402a527c0948889cef4b02c2f7b7d8
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
