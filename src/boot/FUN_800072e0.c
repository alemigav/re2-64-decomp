/* FUN_800072e0
 * image   boot (boot), base 0x80000480
 * address 0x800072e0  body 0x800072e0..0x800072ff  size 35 B
 * sha256  761a107dc1604265f3a956af8de7f1515738f9ca1935369123267fad7a9dbf65
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800072e0(void)

{
  setCopReg(0,Status,Status & 0xfffffffe);
  return Status & 1;
}
