/* func_800aa8e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa8e4  body 0x800aa8e4..0x800aa93f  size 95 B
 * body sha256 743f8e67aaac63860874b6ea0f05231bdaf2e71359e210984983cd7eb0b87c27
 * provider record sha256 9056b3ea11c989cc0ba12854856a64bfb15ee4b6f0c9a163fddafc995e41c9de
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800aa8e4(int param_1)

{
  int in_v0;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (in_v0 != 0) {
    FUN_800a5678();
    if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x34);
    }
    FUN_800a56c0();
  }
  return uVar1;
}
