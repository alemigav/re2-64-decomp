/* FUN_80033160
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033160  body 0x80033160..0x800331b7  size 91 B
 * sha256  ce92b5817e9982f482e2098ba803fcdbd94add3e942cbc69b1152b9a784cece8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033160(int param_1,int param_2)

{
  short sVar1;
  
  sVar1 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                       (int)*(short *)(param_2 + 0x2a),(int)*(short *)(param_2 + 0x32));
  return (((int)*(short *)(param_2 + 0x66) - (int)sVar1) + 0x400U & 0xfff) < 0x800;
}
