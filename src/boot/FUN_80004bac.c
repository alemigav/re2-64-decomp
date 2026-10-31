/* FUN_80004bac
 * image   boot (boot), base 0x80000480
 * address 0x80004bac  body 0x80004bac..0x80004be3  size 59 B
 * sha256  a3adb1ccb3e72b03a078f120fa952de71321622a9faeffc9a108a6682cf02be2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004bac(void)

{
  (**(code **)(_DAT_80012884 * 4 + -0x7ffed774))();
  return;
}
