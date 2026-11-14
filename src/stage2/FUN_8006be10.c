/* FUN_8006be10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006be10  body 0x8006be10..0x8006be9f  size 144 B
 * body sha256 e474c43e70d12719333d490cc7bdd31c322eb4cb4d6a9be3af2e19b51cf61ec9
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (32 of 36 -> 36 of 36) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006be10.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_801127f4;












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
