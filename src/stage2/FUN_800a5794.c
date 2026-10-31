/* FUN_800a5794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5794  body 0x800a5794..0x800a57db  size 75 B
 * body sha256 daf62f988e110544dc7d5f143374b5d49c7006b794da805e92ac44bc14276363
 * provider record sha256 cb0abfc51da0ef1d2e3c318eef882e1008003c42a631e223edc22c5324d97f50
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5794(void)

{
  osCreateMesgQueue(0x80143fb0,0x80143fc8,1);
  osSendMesg(0x80143fb0,0,0);
  return;
}
