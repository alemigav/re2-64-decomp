/* FUN_8005cad8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cad8  body 0x8005cad8..0x8005cb0b  size 55 B
 * sha256  72fdcf45b0db3a8428ebeb30926546f42aebb4de6076f82363d574ae1ef6b19d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005cad8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
