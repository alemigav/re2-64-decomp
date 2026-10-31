/* FUN_8006bccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bccc  body 0x8006bccc..0x8006bd37  size 111 B
 * sha256  c492c44150a5dee9e140950a82de5a6aba14e7b53b1a74a930c063d360cdbf95
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bccc(int param_1)

{
  while (DAT_801127e0 + param_1 != 0) {
    osRecvMesg(0x80139fb0,&DAT_801127ec,1);
  }
  return;
}
