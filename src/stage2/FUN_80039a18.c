/* FUN_80039a18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039a18  body 0x80039a18..0x80039a97  size 128 B
 * body sha256 9b545486abd3bbe58b5fc153159ac0bb56564e0daf4f41b158bd930d61116f08
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80039a18.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80039a18(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  param_3 = param_3 >> 1;
  puVar1 = (undefined2 *)(param_1 + param_3 * 2);
  puVar2 = (undefined2 *)(param_2 + param_3 * 2);
  if ((((param_5 == 0) || (param_5 == 8)) || (param_5 == 9)) ||
     ((param_5 == 0x1f || (param_5 == 0x26)))) {
    FUN_8003994c();
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar2;
    }
  }
  return;
}
