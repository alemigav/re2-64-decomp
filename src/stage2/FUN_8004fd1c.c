/* FUN_8004fd1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fd1c  body 0x8004fd1c..0x8004fea3  size 395 B
 * body sha256 e245464edfda028352f45fdf88b37eeb1d7c062619f56026a86da37f602ca773
 * provider record sha256 858e36c3c85fcea83676d0cf0ffa9eae6ca3ed9ce27bcfb8c133ffc5f59ad507
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004fd1c(undefined1 *param_1,short *param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  
  switch(param_3) {
  case 0:
    *param_2 = (ushort)(byte)param_1[3] << 4;
    return;
  case 1:
    if ((byte)param_1[2] == 0) {
      trap(0x1c00);
    }
    *param_2 = (short)((uint)(byte)param_1[1] / (uint)(byte)param_1[2] << 4);
    if ((uint)(byte)param_1[1] != (uint)(byte)param_1[3] * (uint)(byte)param_1[2] - 1) {
      param_1[1] = param_1[1] + 1;
      return;
    }
    break;
  case 2:
    if ((byte)param_1[2] == 0) {
      trap(0x1c00);
    }
    *param_2 = (short)((uint)(byte)param_1[1] / (uint)(byte)param_1[2] << 4);
    cVar1 = param_1[1];
    param_1[1] = cVar1 + 1U;
    if ((uint)(byte)(cVar1 + 1U) == (uint)(byte)param_1[3] * (uint)(byte)param_1[2]) {
      param_1[1] = 0;
      return;
    }
    break;
  case 3:
    if ((byte)param_1[2] == 0) {
      trap(0x1c00);
    }
    *param_2 = (short)((uint)(byte)param_1[1] / (uint)(byte)param_1[2] << 4);
    bVar2 = param_1[1] + 1;
    param_1[1] = bVar2;
    if ((uint)bVar2 == (uint)(byte)param_1[3] * (uint)(byte)param_1[2]) {
      param_1[1] = bVar2 - param_1[2];
      *param_1 = 0x84;
      return;
    }
    break;
  case 4:
    cVar1 = param_1[1];
    param_1[1] = cVar1 - 1U;
    if ((byte)param_1[2] == 0) {
      trap(0x1c00);
    }
    *param_2 = (short)((uint)(byte)(cVar1 - 1U) / (uint)(byte)param_1[2] << 4);
    if (param_1[1] == '\0') {
      *param_1 = 0x83;
      param_1[1] = param_1[2];
    }
  }
  return;
}
