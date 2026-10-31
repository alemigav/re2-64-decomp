/* FUN_8006bb0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bb0c  body 0x8006bb0c..0x8006bbbb  size 179 B
 * sha256  2eedccbfcd44114e8b425e24fbef4f9f20764cedf90146b753e4036ada121389
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
