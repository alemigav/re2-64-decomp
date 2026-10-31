/* FUN_8000d9c0
 * image   boot (boot), base 0x80000480
 * address 0x8000d9c0  body 0x8000d9c0..0x8000d9d7  size 27 B
 * body sha256 687fd0effce760098d29bfd079e950578fc7939020c786bf01ba017538f405e1
 * provider record sha256 e97b3d64522321f78fa72c1c9c7053c757b8396b5697819c6a91e21aeddd1201
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8000d9c0(void)

{
  return (_DAT_a4040010 & 0x1c) != 0;
}
