/* FUN_800878fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800878fc  body 0x800878fc..0x8008794b  size 80 B
 * body sha256 3b60696e33d3e8459961608c40433aeadd2a0c5734a5059b33ccb4462d4f2861
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800878fc.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_800878fc(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0x5e)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0x40) + param_3 * *(short *)(param_1 + 0x5c) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0x44) + param_3 * *(short *)(param_1 + 0x5c) * 4;
  }
  return;
}
