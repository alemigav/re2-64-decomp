/* FUN_80040cf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040cf4  body 0x80040cf4..0x80040d2b  size 56 B
 * body sha256 3a054363327ce4da7d36ee454f090df008e1c6f2c6c1c4c438c3051e69d6668e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80040cf4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80040cf4(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [32];
  
  FUN_8004226c(param_1,param_2,auStack_28);
  FUN_800424bc(auStack_28,param_2);
  return param_2;
}
