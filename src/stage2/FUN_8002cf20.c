/* FUN_8002cf20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002cf20  body 0x8002cf20..0x8002cfdb  size 188 B
 * body sha256 39356413b642d6ae933d19191ff799d75ceee5cffbab8a33cc7fd3a8c0432464
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002cf20.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();












undefined4 FUN_8002cf20(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x58] == 0) && (iVar1 = FUN_8002c9c0(), iVar1 == 0)) {
    return 0;
  }
  if (param_1[0x58] == *(int *)(param_1[0x5d] + 0x58) + 0xd0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x5a;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x5d] + 0x58);
    (**(code **)(*param_1 + 4))(param_1,2);
    param_1[0x58] = 0;
  }
  else {
    iVar1 = (**(code **)(param_1[5] + 0x14))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  *(uint *)(param_1[0x5d] + 0x58) = *(int *)(param_1[0x5d] + 0x58) + 1U & 7;
  return 1;
}
