/* FUN_8002dd34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002dd34  body 0x8002dd34..0x8002ddb3  size 128 B
 * body sha256 50c81be1bb529469d09ca169862485b5fc0b551732b7cd13994b5dfe3fb8a2f9
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002dd34.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef void code();












void FUN_8002dd34(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if ((*(int *)(iVar1 + 0x14) == 0) || (*(int *)(iVar1 + 0x14) == 2)) {
    if (param_1[0x11] != 0) {
      (**(code **)(param_1[0x62] + 8))();
    }
    *(undefined4 *)(iVar1 + 0x14) = 3;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)();
  }
  return;
}
