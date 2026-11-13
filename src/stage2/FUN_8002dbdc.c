/* FUN_8002dbdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002dbdc  body 0x8002dbdc..0x8002dd33  size 344 B
 * body sha256 21099a4a9a9049452114022e35267c37768f1bd83d853ce8e51e12ab9c685775
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002dbdc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef void code();












void FUN_8002dbdc(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if (*(int *)(iVar1 + 0x14) == 0) {
    FUN_8002d710();
    *(uint *)(iVar1 + 8) = (uint)(*(int *)(iVar1 + 0x20) == 0);
    if (param_1[0x10] == 0) {
      if (*(int *)(iVar1 + 0x10) == 0) {
        (**(code **)param_1[0x61])(param_1);
      }
      (**(code **)param_1[0x60])(param_1);
      if (param_1[0x11] != 0) {
        (**(code **)param_1[0x62])(param_1,*(undefined4 *)(iVar1 + 0x20));
      }
      (**(code **)param_1[0x5c])(param_1,(uint)(*(int *)(iVar1 + 0x20) != 0) << 2);
    }
    (**(code **)param_1[0x5f])(param_1);
    (**(code **)(param_1[0x5f] + 4))(param_1);
    (**(code **)param_1[0x5e])(param_1);
    (**(code **)param_1[0x5b])(param_1,0);
    (**(code **)param_1[0x5a])(param_1,0);
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 0xc) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(param_1[2] + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  }
  return;
}
