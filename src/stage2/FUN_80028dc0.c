/* FUN_80028dc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028dc0  body 0x80028dc0..0x80028e83  size 196 B
 * body sha256 cf6a0c767901bb7dac85014897d61f485e30bf1e7d762f7f399712bbe164df50
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80028dc0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef void code();
extern unsigned int DAT_800b6b30;












undefined4 FUN_80028dc0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[5];
  iVar1 = func_0x80004cfc(puVar2[7],puVar2[8],0,&DAT_800b6b30);
  if (iVar1 == 0) {
    if (puVar2[9] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x24;
      (**(code **)*param_1)(param_1);
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x6a;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    iVar1 = 2;
    *(undefined1 *)puVar2[8] = 0xff;
    *(undefined1 *)(puVar2[8] + 1) = 0xd9;
  }
  puVar2[1] = iVar1;
  puVar2[9] = 0;
  *puVar2 = puVar2[8];
  return 1;
}
