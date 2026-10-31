/* FUN_8006bb0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bb0c  body 0x8006bb0c..0x8006bbbb  size 179 B
 * body sha256 2edda8d0add39f38f1bef9e52ebb721d9bdde232039b0ecea5e4a7aa0e473f87
 * provider record sha256 18a770f9a3d6af6f121b6c99b620cb9d02ba5c554562700841c0cc4b0af59281
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined * FUN_8006bb0c(int param_1)

{
  undefined *puVar1;
  int local_18 [2];
  
  if (param_1 == 1) {
    puVar1 = (undefined *)0x0;
  }
  else if (param_1 < 0) {
    puVar1 = DAT_80112a1c;
  }
  else {
    if (param_1 == 0) {
      param_1 = 1;
      DAT_801127dc = DAT_80112a1c;
    }
    do {
      osRecvMesg(0x80139f50,local_18,1);
    } while (local_18[0] < (int)(DAT_801127dc + param_1));
    puVar1 = &DAT_80110000;
    DAT_801127dc = DAT_80112a1c;
  }
  return puVar1;
}
