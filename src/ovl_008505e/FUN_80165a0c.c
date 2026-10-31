/* FUN_80165a0c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165a0c  body 0x80165a0c..0x80165a5b  size 83 B
 * sha256  448c2374e520d0fea2c2aa9693011fae17543b94484972fe047c220271660806
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165a0c(uint *param_1)

{
  if (((*param_1 & 0x18000000) != 0) && (*(char *)((int)param_1 + 0x2b5) == '\0')) {
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0xff74;
    *(undefined2 *)(param_1 + 0x78) = 0xf0;
  }
  FUN_80164d90();
  return;
}
