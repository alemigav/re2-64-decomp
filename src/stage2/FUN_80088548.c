/* FUN_80088548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088548  body 0x80088548..0x8008857b  size 52 B
 * body sha256 9e96a3e9966bb9e5c25fc5f8c56c8896202856259dd5ffba3cbc0fedc003a9a3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80088548.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned int DAT_8012bae0;












void FUN_80088548(undefined2 *param_1,int param_2)

{
  DAT_8012bae0 = param_1;
  *param_1 = 1;
  param_1[1] = 0;
  *(int *)(param_1 + 2) = param_2 + -0x20;
  *(undefined2 *)((int)param_1 + param_2 + -0x10) = 8;
  *(undefined2 *)((int)param_1 + param_2 + -0xe) = 0;
  *(undefined4 *)((int)param_1 + param_2 + -0xc) = 0;
  return;
}
