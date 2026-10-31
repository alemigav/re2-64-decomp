/* FUN_801668b4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801668b4  body 0x801668b4..0x8016696b  size 187 B
 * sha256  ace8dba6cbcddfba82d36868170ba89f48414e0b53daeb39de0986768ccac49f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801668b4(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x1e8) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x2cc) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  func_0x80036f64(param_1,*(int *)(param_1 + 0x2c4) + 0x28,0x40);
  func_0x80036d14(param_1,0,0xf,0);
  if ((*(uint *)(param_1 + 0x28c) < 0x9c4) || (0xff < *(short *)(param_1 + 500))) {
    *(undefined1 *)(param_1 + 0x2b5) = 2;
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  return;
}
