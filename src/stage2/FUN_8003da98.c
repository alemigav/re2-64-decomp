/* FUN_8003da98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003da98  body 0x8003da98..0x8003dadb  size 71 B
 * sha256  dbd325ce3ab3e79362626fee987113da6c9cd3f064dc2f50fc9e4fd39ca3dc5b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003da98(void)

{
  ushort uVar1;
  
  FUN_80039c34();
  *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
  uVar1 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0x42) = (uVar1 & 3) + 10;
  return;
}
