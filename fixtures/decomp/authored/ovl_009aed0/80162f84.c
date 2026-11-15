typedef unsigned short undefined2;
typedef unsigned int uint;












void FUN_80162f84(int param_1,int param_2)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(param_1 + 0x234) + param_2 * 0x178);
  *puVar2 = *puVar2 | 0x4a;
  sVar1 = *(short *)(param_1 + 0x66);
  *(undefined2 *)(puVar2 + 0x4e) = 0x8000;
  *(undefined2 *)(puVar2 + 0x4d) = 0;
  *(short *)((int)puVar2 + 0x132) = 0xfff6;
  *(undefined2 *)((int)puVar2 + 0x136) = 0;
  *(undefined2 *)(puVar2 + 0x4f) = 0;
  puVar2[0x18] = 0x202038;
  *(short *)(puVar2 + 0x4c) = sVar1 + 0x800;
  return;
}
