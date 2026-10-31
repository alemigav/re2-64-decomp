/* FUN_8000cd00
 * image   boot (boot), base 0x80000480
 * address 0x8000cd00  body 0x8000cd00..0x8000cd3f  size 67 B
 * sha256  1af26a14f567a0b63ff3526de3abd868ed7cd824951eac6b8d1095d59e3bd8fa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cd00(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  _DAT_800128d0 = _DAT_800128d0 | param_1;
  FUN_80007300(uVar1);
  return;
}
