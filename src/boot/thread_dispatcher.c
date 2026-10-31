/* thread_dispatcher
 * image   boot (boot), base 0x80000480
 * address 0x80000c68  body 0x80000c68..0x80000cb3  size 79 B
 * body sha256 056cfaac0ec6c0db8369f1a619b1d5050747b1c294f1f778d775ffa98fef2354
 * provider record sha256 1d3f40181b1aa99f9bf9157b61566c637ebd5b27363716c434e4daa9e1fe30ac
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thread_dispatcher(void)

{
  int *in_k0;
  
  if (in_k0[1] < *(int *)((int)_DAT_80012948 + 4)) {
    FUN_80000f08(&DAT_80012948,in_k0);
    FUN_80000f60();
    return;
  }
  *in_k0 = (int)_DAT_80012948;
  _DAT_80012948 = in_k0;
  FUN_80000f60();
  return;
}
