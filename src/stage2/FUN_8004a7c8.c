/* FUN_8004a7c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a7c8  body 0x8004a7c8..0x8004a7f3  size 44 B
 * body sha256 92093f91fa76ea8913e5a2e94e25505f174d8af7a4be5e16a3c24ac150be0a38
 * recovered byte-exact (read from the words (M448): the image ORs 0x200 into the FOURTH argument in place (`ori a3,a3,512`) between the shift and the combining `or`, so `p3 << 4 | p4 | 0x200` is wrong in two ways — it folds 512 into the third argument and it loses the in-place update. Naming the shift and hoisting `p4 |= 0x200` forces the image's evaluation order.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004a7c8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_8004a7c8(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5)

{
  unsigned int t;
  t = param_3 << 4;
  param_4 = param_4 | 0x200;
  FUN_8004a7f4(param_1,param_2,t | param_4,&param_5);
  return;
}
