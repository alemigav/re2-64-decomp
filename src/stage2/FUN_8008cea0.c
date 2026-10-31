/* FUN_8008cea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008cea0  body 0x8008cea0..0x8008d00b  size 367 B
 * sha256  8b6d5bac2ac7aef70ad2fd2672622d344718b7b27f438556e673c3951722de8c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8008cea0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_8012bfa0;
  uVar2 = (uint)(byte)(&DAT_800e8ec9)[uVar3 * 4];
  iVar1 = FUN_800837ac(&DAT_800e8b58,param_1);
  if (iVar1 != 0) {
    return 1;
  }
  if (uVar2 != 0xff) {
    if (((param_1 == 0xf) || (param_1 == 0x13)) || (param_1 == 0x12)) {
      if ((short)(DAT_8012bfc4 + 1) < 8) {
        DAT_8012bfc4 = DAT_8012bfc4 + 1;
        return 1;
      }
      DAT_8012bfc4 = 0;
      if (uVar2 == 0) {
        DAT_8012bfc4 = 0;
        return 0;
      }
      uVar2 = uVar2 - 1;
      FUN_8008c33c(uVar3,uVar2);
    }
    if (param_1 == 0x10) {
      if ((short)(DAT_8012bfc4 + 1) < 8) {
        DAT_8012bfc4 = DAT_8012bfc4 + 1;
        return 1;
      }
      DAT_8012bfc4 = 0;
      if (uVar2 == 0) {
        DAT_8012bfc4 = 0;
        return 0;
      }
      uVar2 = uVar2 - 1;
      FUN_8008c33c(uVar3,uVar2);
    }
    if (param_1 == 0xe) {
      if (param_2 == 0) {
        iVar1 = uVar2 - 1;
      }
      else {
        iVar1 = uVar2 - 4;
      }
    }
    else {
      if (uVar2 == 0) {
        return 0;
      }
      iVar1 = uVar2 - 1;
    }
    FUN_8008c33c(uVar3,iVar1);
  }
  return 1;
}
