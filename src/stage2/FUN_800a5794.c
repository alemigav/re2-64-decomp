/* FUN_800a5794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5794  body 0x800a5794..0x800a57db  size 75 B
 * sha256  c8ace224b4666560db64148d5f7d8704db5f9a813d2db58d79fda8eddcfc51f7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5794(void)

{
  osCreateMesgQueue(0x80143fb0,0x80143fc8,1);
  osSendMesg(0x80143fb0,0,0);
  return;
}
