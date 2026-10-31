/* FUN_8006b9f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b9f0  body 0x8006b9f0..0x8006ba17  size 43 B
 * body sha256 c56c6501fd64d09f6fb560248eaf9415019d1fef997b8f8b8b1b165ad09afc1e
 * provider record sha256 f6942a2846cdaf64ea06219e524004b5296522114abad69cb91cb292e51f30ff
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006b9f0(void)

{
  undefined1 auStack_10 [8];
  
  osRecvMesg(0x80139fd0,auStack_10,1);
  return;
}
