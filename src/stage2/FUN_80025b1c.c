/* FUN_80025b1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025b1c  body 0x80025b1c..0x80025ba7  size 143 B
 * sha256  d2b1982b0df5b63d69eee93a4770ff6c300a3e1aba6a6a7fe39098e99763ae65
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025b1c(int param_1)

{
  param_1 = param_1 * 0x28;
  FUN_8006cdf0(*(undefined4 *)(&DAT_800c4f80 + param_1),*(undefined4 *)(&DAT_800c4f84 + param_1),
               *(undefined4 *)(&DAT_800c4f88 + param_1),*(undefined4 *)(&DAT_800c4f8c + param_1),
               *(undefined4 *)(&DAT_800c4f90 + param_1),*(undefined4 *)(&DAT_800c4f94 + param_1),
               *(undefined4 *)(&DAT_800c4f98 + param_1),*(undefined4 *)(&DAT_800c4f9c + param_1),
               *(undefined4 *)(&DAT_800c4fa0 + param_1),*(undefined4 *)(&DAT_800c4fa4 + param_1),0,0
              );
  return;
}
