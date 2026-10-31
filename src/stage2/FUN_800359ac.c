/* FUN_800359ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800359ac  body 0x800359ac..0x80035a7b  size 211 B
 * sha256  5ce9050d895352e61efc95b9e3a79aa87548cab4372b6aa711b023497df96ce3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800359ac(void)

{
  undefined **ppuVar1;
  
  if (DAT_800e110c < 0) {
    ppuVar1 = &PTR_DAT_80129dac;
  }
  else {
    ppuVar1 = &PTR_DAT_80129c8c;
  }
  if (*(short *)(ppuVar1[DAT_800e8ca8] + DAT_800e8caa * 2) != -1) {
    *(undefined4 *)(DAT_800df92c + 0x60) = DAT_800df934;
    DAT_800df934 = func_0x80005f4c(*(undefined2 *)(ppuVar1[DAT_800e8ca8] + DAT_800e8caa * 2),
                                   DAT_800df934);
  }
  return;
}
