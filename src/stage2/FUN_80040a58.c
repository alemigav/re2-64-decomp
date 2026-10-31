/* FUN_80040a58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040a58  body 0x80040a58..0x80040aa7  size 83 B
 * body sha256 6dfafc08df6aefa4c547d7b98dee4fa170ac387d16731434b3900742c96fbce6
 * provider record sha256 73345554e77363bb0e92785d24cf350910417dc58044f165e834926abfc8da12
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040a58(int param_1,int param_2)

{
  float fVar1;
  
  fVar1 = (float)FUN_80047d70((float)param_1 * 0.00024414062,(float)param_2 * 0.00024414062);
  return (int)(fVar1 * 651.8986);
}
