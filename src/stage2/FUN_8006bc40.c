/* FUN_8006bc40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bc40  body 0x8006bc40..0x8006bccb  size 143 B
 * sha256  3e71e544bd263891d7bad2228f0e3db5d426ad4242ac689810e6b4b4f74fb151
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006bc40(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
    if (DAT_801127e0 != 0) {
      while (DAT_801127e0 != 0) {
        osRecvMesg(0x80139f90,&DAT_801127e8,1);
      }
      uVar1 = 1;
      DAT_801127e0 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
