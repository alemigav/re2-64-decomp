/* FUN_800a2218
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2218  body 0x800a2218..0x800a228b  size 119 B
 * sha256  48db0fddea630965b2df6e365c244692b1ff5219683b8466583f81d262c59db8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a2218(undefined1 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a13c4(param_1,param_2,param_3,param_4);
    FUN_800a56c0();
  }
  return;
}
