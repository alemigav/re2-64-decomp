/* FUN_8008cce4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008cce4  body 0x8008cce4..0x8008ce9f  size 447 B
 * sha256  9cb2bf16d5ae0b117b4f343acfd8b1b0c22aa183b8c61df6cc4eee507e58104f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8008cce4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0x12) && (iVar2 = FUN_800837ac(&DAT_800e8b58,0x12), iVar2 != 0)) {
    DAT_800e110c = DAT_800e110c | 0x800000;
  }
  if (((param_1 == 0xf) && ((&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] == -1)) ||
     ((param_1 == 0x11 && ((&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] == -1)))) {
    uVar1 = 1;
    DAT_800e110c = DAT_800e110c | 0x800000;
  }
  else if ((DAT_8012bfa0 == 0x80) || (iVar2 = FUN_800837ac(&DAT_800e8b58,param_1), iVar2 == 0)) {
    if (param_1 == 0xe) {
      if (DAT_8012bfa0 != 0x80) {
        if ((byte)(&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] < 5) {
          return 0;
        }
        return 1;
      }
    }
    else if ((DAT_8012bfa0 != 0x80) && ((&DAT_800e8ec9)[(uint)DAT_8012bfa0 * 4] != '\0')) {
      return 1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
