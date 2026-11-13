/* inflate_free
 * image   boot (boot), base 0x80000480
 * address 0x80004594  body 0x80004594..0x800045db  size 72 B
 * body sha256 93863c453c99aa59d55e510fb395fce0bc54f41e1a28ad50af4566a02e2ef977
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004594.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void inflate_free(int param_1,uint param_2)

{
  FUN_800014ac(*(undefined4 *)(param_1 + 0x4c));
  if ((param_2 & 1) != 0) {
    func_0x8008b0a4(param_1);
  }
  return;
}
