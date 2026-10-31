/* FUN_80073f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073f64  body 0x80073f64..0x80073fb3  size 83 B
 * sha256  a0733c577a511594ea3dbb137131d5bce11a56810f31aa2cac2cd40890a8997d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073f64(undefined2 *param_1)

{
  if ((DAT_800e1110 & 0x2000000) == 0) {
    FUN_8006d628(*param_1,*(undefined1 *)((int)param_1 + 3));
  }
  return 0;
}
