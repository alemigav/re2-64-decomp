/* FUN_8002fd00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fd00  body 0x8002fd00..0x8002fd37  size 56 B
 * body sha256 1e2c0bcd9d0f04238b5e678d59ed1bfc98af69f29de5793038828040e2c70085
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002fd00.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef void code();












void FUN_8002fd00(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x14) = 0x2e;
  *(undefined4 *)(*param_1 + 0x18) = param_2;
  (**(code **)*param_1)();
  return;
}
