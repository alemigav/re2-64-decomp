/* FUN_80083a4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083a4c  body 0x80083a4c..0x80083ac3  size 123 B
 * sha256  e6fded9bf768da43c8d76cd61971ce80640851be2287daa3800a770f4f8c9644
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083a4c(int param_1)

{
  short local_10 [2];
  short local_c;
  
  local_c = 0;
  local_10[0] = (short)((int)((uint)*(ushort *)(param_1 + 300) * 0xb3) >> 7);
  FUN_800837d0((int)*(short *)(param_1 + 0x66),local_10,local_10);
  *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x2a) + local_10[0];
  *(short *)(param_1 + 0x1fc) = *(short *)(param_1 + 0x32) + local_c;
  return;
}
