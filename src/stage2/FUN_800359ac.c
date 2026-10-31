/* FUN_800359ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800359ac  body 0x800359ac..0x80035a7b  size 211 B
 * body sha256 5ff32d677bf11716a96e18836d3cfe62a81744a813b391903132911e8945d2af
 * provider record sha256 e0cc31fd32511a26092ce54908472646fecfe517995a573c60e64eef66faa40d
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
