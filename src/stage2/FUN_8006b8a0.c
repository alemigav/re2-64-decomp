/* FUN_8006b8a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b8a0  body 0x8006b8a0..0x8006b9bb  size 287 B
 * sha256  7b245396eae5fc54ba2886e8723d668646da1dd821862e91209e6fd61f92d76e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8006b8b4) */
/* WARNING: Removing unreachable block (ram,0x8006b920) */
/* WARNING: Removing unreachable block (ram,0x8006b96c) */
/* WARNING: Removing unreachable block (ram,0x8006b934) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b8a0(void)

{
  osStartThread(&DAT_80112da0);
  func_0x8000cdf0(&DAT_80112da0,0x1e);
  func_0x8000cdf0(&DAT_80112bf0,0x14);
  func_0x8000cdf0(&DAT_80112f50,0x15);
  func_0x8000cdf0(&DAT_80113100,0x15);
  return;
}
