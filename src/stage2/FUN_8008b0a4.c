/* FUN_8008b0a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b0a4  body 0x8008b0a4..0x8008b0eb  size 75 B
 * sha256  30eb8ab257d3607466551512045c9939c2fdd3d98fc55cffd1c7777816bbbe03
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008b0a4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x8000cd40(1);
  if (param_1 != 0) {
    FUN_8008b040(param_1);
  }
  func_0x8000cd40(uVar1);
  return;
}
