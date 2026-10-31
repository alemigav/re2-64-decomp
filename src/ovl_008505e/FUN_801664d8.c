/* FUN_801664d8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801664d8  body 0x801664d8..0x80166527  size 83 B
 * sha256  89c374c75e529cd1e46b4d3d163596dc375d0330387d351db87af39a8339321e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801664d8(int param_1)

{
  *(undefined1 *)(param_1 + 0x25d) = 2;
  func_0x800347b0(param_1,(int)*(short *)(param_1 + 0x66));
  *(undefined1 *)(param_1 + 0x25d) = 3;
  func_0x800347b0(param_1,(int)*(short *)(param_1 + 0x66));
  *(undefined1 *)(param_1 + 0x25d) = 2;
  return;
}
