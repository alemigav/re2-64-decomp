/* FUN_80007ef0
 * image   boot (boot), base 0x80000480
 * address 0x80007ef0  body 0x80007ef0..0x80007f47  size 91 B
 * body sha256 5c4d4519a411e3541508b7edb96e447c5b95ef9d770d73157cf045a26a21b2bc
 * provider record sha256 3d0600ff2d49e2ee1216df82e67382cf7dd2954a28cb9643be60993553eebcc6
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
