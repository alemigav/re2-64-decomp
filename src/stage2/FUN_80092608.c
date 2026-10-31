/* FUN_80092608
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092608  body 0x80092608..0x8009264f  size 75 B
 * body sha256 66825cc37dcecc7da03d1604877acf888bde2c94e4bfda91bbe805d563b9bc67
 * provider record sha256 b923c0c8de0bccded70b3f6ddf9cbec4464b1d11c208cc71d7363a74832aeb68
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092608(void)

{
  if ((DAT_800df918 & 0x6000) != 0) {
    FUN_80077adc(0x4050000,0);
    DAT_8012bf99 = 0;
  }
  return;
}
