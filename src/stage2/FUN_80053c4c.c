/* FUN_80053c4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053c4c  body 0x80053c4c..0x80053c77  size 47 B
 * body sha256 139ec762a767a0ba1c8ced25c28ba492f0271fa9bf6ae41c84f80c822b07e85b
 * provider record sha256 4293a3a663fe00946daa827f36488c6f9c750bda2d26c3ac774ea12370a9c90e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053c4c(byte param_1)

{
  DAT_8010d940[(uint)*DAT_8010d940 + (uint)DAT_8010d940[1] * 0x1e + 4] = param_1;
  return;
}
