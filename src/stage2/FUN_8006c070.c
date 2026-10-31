/* FUN_8006c070
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006c070  body 0x8006c070..0x8006c0d3  size 103 B
 * sha256  a0ea0a64dd221df7a45f84331ae16551e75d0d4b5a79114c3697eb7b0d619b32
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006c070(int param_1)

{
  DAT_80112784 = param_1;
  if (param_1 == 0) {
    for (; DAT_80112788 != 0; DAT_80112788 = DAT_80112788 + -1) {
      osSendMesg(&DAT_80112a24,0,0);
    }
  }
  return;
}
