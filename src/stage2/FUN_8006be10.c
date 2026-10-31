/* FUN_8006be10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006be10  body 0x8006be10..0x8006be9f  size 147 B
 * sha256  9904f036e69b960b3aea3e09e71d418d2e43ac5f226f66c07944cc41ebe5622b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006be10(void)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if ((DAT_801127f4 & 1) != 0) {
    uVar1 = 1;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 8;
  if ((DAT_801127f4 & 2) != 0) {
    uVar1 = 4;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 0x20;
  if ((DAT_801127f4 & 4) != 0) {
    uVar1 = 0x10;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 0x80;
  if ((DAT_801127f4 & 8) != 0) {
    uVar1 = 0x40;
  }
  func_0x8000e9d0(uVar1);
  return;
}
