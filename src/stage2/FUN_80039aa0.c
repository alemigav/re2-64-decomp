/* FUN_80039aa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039aa0  body 0x80039aa0..0x80039b5b  size 188 B
 * body sha256 9740e3d5e61617cedff61ff6b6ee89cbc0e1110b0be77c9c2a5bd7ee793efc7b
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80039aa0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;












void FUN_80039aa0(undefined4 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  
  *param_1 = *param_2;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 1));
  *(undefined2 *)(param_1 + 1) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 6));
  *(undefined2 *)((int)param_1 + 6) = uVar1;
  param_1[2] = param_2[2];
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 3));
  *(undefined2 *)(param_1 + 3) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0xe));
  *(undefined2 *)((int)param_1 + 0xe) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 4));
  *(undefined2 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0x12));
  *(undefined2 *)((int)param_1 + 0x12) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 5));
  *(undefined2 *)(param_1 + 5) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0x16));
  *(undefined2 *)((int)param_1 + 0x16) = uVar1;
  return;
}
