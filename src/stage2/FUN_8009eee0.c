/* FUN_8009eee0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009eee0  body 0x8009eee0..0x8009ef4f  size 115 B
 * body sha256 76a5adb14ee05b2dc9cf42b38c1b3604724fa23151fdb1f2f7926e7fea59f75e
 * provider record sha256 e982f6de5b19c18fd78fac221b3dd25d68333521e9bf956bf039e62a44111d6f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009eee0(int param_1,int param_2)

{
  DAT_80134318 = param_1 + DAT_80134420 & 0xfffffff;
  DAT_8013431c = param_2 + DAT_80134420 & 0xfffffff;
  func_0x8000efa0(&DAT_80134318,0x80);
  DAT_801344f4 = 4;
  FUN_8006c044(&DAT_80134468,0);
  return;
}
