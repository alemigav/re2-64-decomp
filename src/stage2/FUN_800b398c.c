/* FUN_800b398c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b398c  body 0x800b398c..0x800b3a67  size 223 B
 * body sha256 e8b7412a6bb41acc9b8d92e3c2846dce7c7e6d3ec7b872743c206e33bc5209be
 * provider record sha256 0b1d3c6deee0483800c9441fe6c00569c8d5100b60d8a34bc00a224f0835daec
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b398c(int param_1)

{
  param_1 = param_1 * 0x1228;
  if ((&DAT_80159d20)[param_1] == '\x01') {
    (&DAT_80159d20)[param_1] = 0;
    if ((_DAT_8015af90 & 1) == 0) {
      (*_DAT_8014400c)(*(undefined4 *)(param_1 + -0x7fea62d0));
    }
  }
  else if ((&DAT_80159d20)[param_1] == '\x02') {
    osRecvMesg(0x8015afa0,0,1);
    FUN_800b4dac(param_1 + -0x7fea74e0);
    (&DAT_80159d20)[param_1] = 3;
    *(undefined1 *)(param_1 + -0x7fea62c8) = 4;
    osSendMesg(0x8015afa0,0,0);
  }
  return;
}
