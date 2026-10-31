/* pi_dma_raw
 * image   boot (boot), base 0x80000480
 * address 0x8000c870  body 0x8000c870..0x8000c93f  size 211 B
 * body sha256 325c74eb6ef3232e3b638692fcc6d2bac1892ab85d5ac5fe350b667de72eff03
 * provider record sha256 02f516560dd6e52402820838d8c504364768c68ef3710d3aa2855dc0047c2fd3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 pi_dma_raw(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  _DAT_a4600000 = FUN_8000e800(param_3);
  _DAT_a4600004 = (_DAT_80000308 | param_2) & 0x1fffffff;
  if (param_1 == 0) {
    piVar1 = (int *)&DAT_a460000c;
  }
  else {
    if (param_1 != 1) {
      return 0xffffffff;
    }
    piVar1 = (int *)&DAT_a4600008;
  }
  *piVar1 = param_4 + -1;
  return 0;
}
