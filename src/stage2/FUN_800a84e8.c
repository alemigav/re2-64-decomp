/* FUN_800a84e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a84e8  body 0x800a84e8..0x800a851b  size 55 B
 * body sha256 6d5503f55f12234fc353b9ac0d94d77274c418eafc602382f265b2c2964be8c7
 * provider record sha256 37cd06d2c3d68bc9912af06b33084d627d06eb8a93b79b51044beb7517e7f4fe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a84e8(int param_1)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x4b) == 0xff) {
    iVar1 = 0x20;
  }
  else {
    iVar1 = (uint)*(byte *)(param_1 + 0x4b) << 2;
  }
  return *(undefined4 *)(iVar1 + -0x7febbff0);
}
