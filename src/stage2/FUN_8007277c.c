/* FUN_8007277c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007277c  body 0x8007277c..0x800727af  size 52 B
 * body sha256 0a5a7cb5ed27ec8382e126894cab099e8aebc1dd681aafeb0d2ffe9ee72d4c65
 * recovered byte-exact (imported: closed by the localtype mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007277c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int uint;












uint FUN_8007277c(int param_1)

{
  short uVar1;
  uint uVar2;
  
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x1c) + 1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  uVar2 = FUN_8008c51c(uVar1);
  return ~uVar2 >> 0x1f;
}
