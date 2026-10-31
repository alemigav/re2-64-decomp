/* func_800b2594
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2594  body 0x800b2594..0x800b2617  size 135 B
 * body sha256 25605fd767f7b1cc0b2cdc72e12aa37942f80a6e4e36e90ebf81c5c4a1cdec13
 * provider record sha256 2bb3d05d31b9590a244546d904a1e84b0059c5d41e355aacf443af0339b7b357
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void func_800b2594(undefined2 param_1,char param_2)

{
  int in_v0;
  int iVar1;
  
  if (in_v0 != 0) {
    FUN_800a5678();
    iVar1 = FUN_800ae034(param_1);
    if (iVar1 != 0) {
      if (param_2 == -2) {
        *(undefined1 *)(iVar1 + 9) = 0x1f;
      }
      else {
        *(char *)(iVar1 + 9) = param_2;
        FUN_800a832c(param_2,3);
      }
    }
    FUN_800a56c0();
  }
  return;
}
