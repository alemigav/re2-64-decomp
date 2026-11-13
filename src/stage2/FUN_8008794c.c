/* FUN_8008794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008794c  body 0x8008794c..0x8008799b  size 80 B
 * body sha256 856c025e7fad6ed6f280ebbb5641845503bde589ea1647b8ce1f328c438b70f1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8008794c.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_8008794c(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0xd6)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0xb8) + param_3 * *(short *)(param_1 + 0xd4) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0xbc) + param_3 * *(short *)(param_1 + 0xd4) * 4;
  }
  return;
}
