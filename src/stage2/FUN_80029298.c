/* FUN_80029298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029298  body 0x80029298..0x80029357  size 195 B
 * body sha256 3ace45f207fd93d36a9a27af52ca2887e84d78dec932a5b720d66fd39286fd30
 * provider record sha256 d05ac066b2b6c4c631d2a1e8b8b75ff1316ef3917d945cb7b3c8fb93cf8fcfab
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80029298(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x60);
  param_1[0x5b] = (int)puVar1;
  *puVar1 = FUN_80028fd0;
  if (param_2 == 0) {
    iVar2 = (**(code **)(param_1[1] + 4))(param_1,1,0x500);
    iVar4 = 9;
    iVar2 = iVar2 + 0x480;
    puVar3 = puVar1 + 9;
    do {
      puVar3[4] = iVar2;
      iVar2 = iVar2 + -0x80;
      iVar4 = iVar4 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar4);
    puVar1[0xe] = 0;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)(param_1);
  }
  return;
}
