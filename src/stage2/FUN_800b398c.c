/* FUN_800b398c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b398c  body 0x800b398c..0x800b3a67  size 223 B
 * sha256  66bd5480f8e594d4c6ec24cb4c4143bb395430f17ab42d58eb041d518ca930a3
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
