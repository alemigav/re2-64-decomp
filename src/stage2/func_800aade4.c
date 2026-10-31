/* func_800aade4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aade4  body 0x800aade4..0x800aaea7  size 199 B
 * body sha256 d43ecc3a0b4e8063122ad9b6c38b1d330f6089f0e53a0a229cafa36b5c51d811
 * provider record sha256 1567b80d8d3a65e3371c282208951806a94877d70310c8ca9173aa1bd10c74d6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800aade4(int param_1,undefined4 *param_2,undefined4 *param_3,byte param_4)

{
  int in_v0;
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  
  if (in_v0 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_800a5678();
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    *(undefined4 *)(param_1 + 0xc) = *param_2;
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    *(undefined4 *)(param_1 + 0x18) = *param_3;
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    fVar3 = (float)param_4 / 127.0;
    *(float *)(param_1 + 0x28) = fVar3;
    if (fVar3 < *(float *)(param_1 + 0x2c)) {
      *(float *)(param_1 + 0x2c) = fVar3;
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
