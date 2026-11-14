/* FUN_80030fd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030fd0  body 0x80030fd0..0x8003104f  size 128 B
 * body sha256 8ffeaaee162beb58f90df3559594cc61f3ad640de0f62366704de42e7534f067
 * recovered byte-exact (imported: closed by the localtype mechanism pass (30 of 32 -> 32 of 32) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80030fd0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int code();












undefined1 FUN_80030fd0(int *param_1)

{
  short uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[5];
  iVar2 = puVar3[1];
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x11;
      (**(code **)*param_1)(param_1);
    }
    iVar2 = puVar3[1];
  }
  puVar3[1] = iVar2 + -1;
  uVar1 = *(undefined1 *)*puVar3;
  *puVar3 = (undefined1 *)*puVar3 + 1;
  return uVar1;
}
