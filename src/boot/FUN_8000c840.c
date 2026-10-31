/* FUN_8000c840
 * image   boot (boot), base 0x80000480
 * address 0x8000c840  body 0x8000c840..0x8000c867  size 43 B
 * body sha256 32d776bff69c91eebd448ad08d6b2b7827ca5a69a6ff42aa81dbfcaa6a65781e
 * provider record sha256 cad2360e201cc615b87459b2144694be4b280899df29be08a12cdbc707466d78
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000c840(void)

{
  osSendMesg(0x80017710,0,0);
  return;
}
