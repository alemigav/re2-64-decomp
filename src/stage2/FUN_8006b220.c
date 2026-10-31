/* FUN_8006b220
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b220  body 0x8006b220..0x8006b263  size 71 B
 * sha256  50a80c62f69d748f1a209b30c2cb2f039150fe14cb6320b9f8a22113dd055f9a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8006b220(int param_1)

{
  return (uint)(*(ushort *)(param_1 + 10) >> 0xb) * -100 +
         (*(ushort *)(param_1 + 10) >> 6 & 0x1f) * -0x708;
}
