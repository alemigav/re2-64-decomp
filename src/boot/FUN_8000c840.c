/* FUN_8000c840
 * image   boot (boot), base 0x80000480
 * address 0x8000c840  body 0x8000c840..0x8000c867  size 43 B
 * sha256  034081bc288d02de9f620b923917212f660bd55e1015ba2f5d69428ffe8efbff
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000c840(void)

{
  osSendMesg(0x80017710,0,0);
  return;
}
