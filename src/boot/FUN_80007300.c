/* FUN_80007300
 * image   boot (boot), base 0x80000480
 * address 0x80007300  body 0x80007300..0x8000731b  size 31 B
 * sha256  2dd79afe081077e796dc893e7e443c907f2390c9272d4354a257d951f1c3423a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80007300(uint param_1)

{
  setCopReg(0,Status,Status | param_1);
  return;
}
