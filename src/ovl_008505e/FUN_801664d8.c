/* FUN_801664d8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801664d8  body 0x801664d8..0x80166527  size 80 B
 * body sha256 7318d11ead80aded0c36cb8251d9627b5dab6eb3a95abc83ff2e54408db59067
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801664d8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;












void FUN_801664d8(int param_1)

{
  *(undefined1 *)(param_1 + 0x25d) = 2;
  func_0x800347b0(param_1,(int)*(short *)(param_1 + 0x66));
  *(undefined1 *)(param_1 + 0x25d) = 3;
  func_0x800347b0(param_1,(int)*(short *)(param_1 + 0x66));
  *(undefined1 *)(param_1 + 0x25d) = 2;
  return;
}
