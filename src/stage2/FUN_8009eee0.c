/* FUN_8009eee0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009eee0  body 0x8009eee0..0x8009ef4f  size 115 B
 * sha256  efec0cc0e00acfaa650733f1b70da6d074de311312a6ac27da09beb6b14f7538
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
