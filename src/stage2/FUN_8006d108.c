/* FUN_8006d108
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d108  body 0x8006d108..0x8006d11f  size 27 B
 * body sha256 cb2e820412442e2ceaa9fe899ef2323397faad8f6318c05159d4140a6dfd4290
 * provider record sha256 9e5416593a99741ac20e37a657b05225504d352ea610ed18a69a772e0d22045b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006d108(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 != 0x10) {
    uVar1 = 0x80;
  }
  return uVar1;
}
