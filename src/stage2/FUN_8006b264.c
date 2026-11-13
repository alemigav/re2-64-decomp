/* FUN_8006b264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b264  body 0x8006b264..0x8006b28b  size 40 B
 * body sha256 0b3a364c3a52be30c44636c569651e35f2d7dc12b62a823aba47cb513ad25b8b
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006b264.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












int FUN_8006b264(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = *(uint *)(param_1 + 0xc); (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
    iVar2 = iVar2 + -0x708;
  }
  return iVar2;
}
