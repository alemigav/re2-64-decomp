/* FUN_800072e0
 * image   boot (boot), base 0x80000480
 * address 0x800072e0  body 0x800072e0..0x800072ff  size 35 B
 * body sha256 fcdf87bb672c63f8439e2e373e984cfe957358fb2c1be0d3c95f02ff00098913
 * provider record sha256 4572263cc30e6da300aeed883ff052f6b3dcf1f5f904bcd38fef97e6d85b35f5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800072e0(void)

{
  setCopReg(0,Status,Status & 0xfffffffe);
  return Status & 1;
}
