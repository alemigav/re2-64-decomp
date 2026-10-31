/* FUN_80166c70
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166c70  body 0x80166c70..0x80166cbb  size 79 B
 * sha256  fb8c7367ae1836e8c33599e8d50e95f01b8a3d581e677b174fb2ef9e8f1187be
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166c70(int param_1,short param_2)

{
  if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
    if ((*(byte *)(param_1 + 0x2cc) & 2) == 0) {
      param_2 = -param_2;
    }
    *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + param_2;
  }
  else {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + param_2;
  }
  *(short *)(param_1 + 0x2c2) = *(short *)(param_1 + 0x2c2) + param_2;
  return;
}
