/* FUN_8005c308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c308  body 0x8005c308..0x8005c32b  size 36 B
 * body sha256 4ed176ac2d9f120fb7192a143007fe65d1ac73927d3cd5726df445443c99b0c8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8005c308.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned char byte;












void FUN_8005c308(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x1780;
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0x234) + 0x1d60;
  }
  *(undefined1 *)(iVar1 + 0x112) = 1;
  return;
}
