/* FUN_80036e70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036e70  body 0x80036e70..0x80036e9f  size 48 B
 * body sha256 253c0fa33913246996058e49d596f1aa669516b15a1fd323da53f148dde0cf41
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80036e70.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












void FUN_80036e70(int param_1)

{
  *(undefined2 *)(param_1 + 0x1d8) = 0;
  *(undefined2 *)(param_1 + 0x1da) = 0;
  *(undefined2 *)(param_1 + 0x1dc) = 0;
  FUN_80040e58(param_1 + 0x1d8,param_1 + 0x1b8);
  return;
}
