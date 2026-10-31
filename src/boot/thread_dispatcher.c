/* thread_dispatcher
 * image   boot (boot), base 0x80000480
 * address 0x80000c68  body 0x80000c68..0x80000cb3  size 79 B
 * sha256  cb474eb03f33b976367816190ea279498b3f6e8e19119465f3e1cfdc9779fcd4
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
