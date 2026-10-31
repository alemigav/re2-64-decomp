/* FUN_8002fc00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc00  body 0x8002fc00..0x8002fc23  size 39 B
 * sha256  d0c32baefc477f445f3c0fb66f447934138af93c8aacf35bd1534de94564488f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002fc00(int param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_1 + iVar2);
      iVar2 = iVar2 + -1;
      *puVar1 = param_2;
    } while (iVar2 != -1);
  }
  return;
}
