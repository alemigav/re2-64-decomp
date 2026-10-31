/* FUN_800040d4
 * image   boot (boot), base 0x80000480
 * address 0x800040d4  body 0x800040d4..0x800040fb  size 43 B
 * body sha256 275222343e46411c5f61ab115e2767ae44edb23c877528dbcd4862afd9eeaa97
 * provider record sha256 0d9b9f86d6b2effb41d3f5ab3b56406463ac9d58b5d7f02c87dc1ff87465d575
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800040d4(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 - param_2;
  return (iVar1 - param_2) * 8 + -0x7ffec140;
}
