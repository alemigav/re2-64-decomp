/* FUN_8004a7a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a7a0  body 0x8004a7a0..0x8004a7c7  size 40 B
 * body sha256 211edb98476d131f8eab9d2062014746a6215ad007b560b85b0dbb7df1522ade
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004a7a0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_8004a7a0(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  FUN_8004a7f4(param_1,param_2,param_3 << 4 | param_4,&param_5);
  return;
}
