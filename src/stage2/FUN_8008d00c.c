/* FUN_8008d00c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d00c  body 0x8008d00c..0x8008d08f  size 135 B
 * sha256  82c55aa42d9c8dad88f75d7c7d77e6c9efe1440af10220edf2f8e35ed4e78077
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008d00c(void)

{
  uint uVar1;
  
  uVar1 = FUN_8008c51c(*(&PTR_DAT_8012ffac)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa0 * 4] * 2]
                      );
  if (DAT_8012bfa2 == '\x11') {
    uVar1 = 0;
  }
  else {
    uVar1 = ~uVar1 >> 0x1f;
  }
  return uVar1;
}
