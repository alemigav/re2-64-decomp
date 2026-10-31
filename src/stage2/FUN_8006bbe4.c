/* FUN_8006bbe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bbe4  body 0x8006bbe4..0x8006bc3f  size 95 B
 * sha256  7dbd68fbfd55c66b94b01a123be488f2b2b0ea0aa236c3181a8f56d24102224a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bbe4(void)

{
  while (DAT_801127e0 != 0) {
    osRecvMesg(0x80139f70,&DAT_801127e4,1);
  }
  return;
}
