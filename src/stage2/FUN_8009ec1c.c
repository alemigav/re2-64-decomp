/* FUN_8009ec1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ec1c  body 0x8009ec1c..0x8009ec97  size 127 B
 * sha256  87adf180af8f996ed942b59efa55f198122b9b916321652d8994c3f4d2b2ae2c
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ec1c(uint *param_1,int param_2)

{
  DAT_801344f4 = 1;
  DAT_80134298 = *param_1 & 0xfffffff;
  DAT_8013429c = param_1[1] & 0xfffffff;
  DAT_801342a4 = param_2 + DAT_80134420 & 0xfffffff;
  DAT_801342a0 = param_1[2] & 0xfffffff;
  func_0x8000f020();
  FUN_8006c044(&DAT_80134428,0);
  return;
}
