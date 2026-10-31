/* FUN_80007ef0
 * image   boot (boot), base 0x80000480
 * address 0x80007ef0  body 0x80007ef0..0x80007f47  size 91 B
 * sha256  993a63b1f072da5a6a0973de647b8be9ab8768879444a0b57b7e6d8d371f0fce
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80007ef0(void)

{
  setCopReg(0,Index,0x1f);
  setCopReg(0,PageMask,0);
  setCopReg(0,EntryHi,0xc0000000);
  setCopReg(0,EntryLo0,0x2000017);
  setCopReg(0,EntryLo1,1);
  TLB_write_indexed_entry(Index,EntryHi,EntryLo0,EntryLo1,PageMask);
  setCopReg(0,EntryHi,EntryHi);
  return;
}
