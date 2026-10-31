/* FUN_8006bd38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bd38  body 0x8006bd38..0x8006bda3  size 111 B
 * sha256  b64fc010abd4809e070b11fcc8a93af0d0e63eff8abca8f16d5d2b9204aafd62
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bd38(int param_1)

{
  while (DAT_801127e0 + param_1 != 0) {
    osRecvMesg(0x8013a100,&DAT_801127f0,1);
  }
  return;
}
