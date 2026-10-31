/* FUN_8000d2b0
 * image   boot (boot), base 0x80000480
 * address 0x8000d2b0  body 0x8000d2b0..0x8000d2c7  size 27 B
 * sha256  85a884b1e41d20823ac87189fa82fd39aadaf79724e539b4b02d351154193cfc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8000d2b0(void)

{
  return (_DAT_a4800018 & 3) != 0;
}
