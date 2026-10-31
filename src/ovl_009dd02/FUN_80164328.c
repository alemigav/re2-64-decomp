/* FUN_80164328
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164328  body 0x80164328..0x801643f3  size 207 B
 * sha256  1cc7e4ac74e80b1bbe296e7648dd7506186506533f46747eda59c98370dcc301
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164328(uint *param_1)

{
  short sVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0xf0;
    *(undefined1 *)((int)param_1 + 0x2b6) = 0;
    *param_1 = *param_1 & 0xfffffbff | 4;
  }
  sVar1 = *(short *)((int)param_1 + 0x1e2) + 0x50;
  *(short *)((int)param_1 + 0x1e2) = sVar1;
  if (0x280 < sVar1) {
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x280;
  }
  func_0x80032bd8(param_1,0,0);
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
    *(undefined2 *)((int)param_1 + 6) = 0x200;
    *param_1 = *param_1 & 0xfffffff7;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    func_0x80077d18(10);
  }
  return;
}
