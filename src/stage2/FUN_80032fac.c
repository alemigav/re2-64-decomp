/* FUN_80032fac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032fac  body 0x80032fac..0x80033023  size 123 B
 * sha256  7c486a31c09ea891e4bf59a62fa059d58614287b62f0ad80f569c1e3e978ea69
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80032fac(int param_1,int param_2,short param_3,short param_4)

{
  short sVar1;
  
  sVar1 = FUN_80032d14((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 10),
                       (int)*(short *)(param_2 + 2),(int)*(short *)(param_2 + 10));
  return (uint)((int)param_4 << 1) <= (((int)sVar1 - (int)param_3) + (int)param_4 & 0xfffU);
}
