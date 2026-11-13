/* inflate_init
 * image   boot (boot), base 0x80000480
 * address 0x80004550  body 0x80004550..0x80004593  size 68 B
 * body sha256 616289424389f55373e0cbff885ea15dfdfa16bcf079e55a0f3d1e2b5f5a929d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004550.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












int inflate_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_800013b0(param_2);
  uVar1 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return param_1;
}
