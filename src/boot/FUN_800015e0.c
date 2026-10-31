/* FUN_800015e0
 * image   boot (boot), base 0x80000480
 * address 0x800015e0  body 0x800015e0..0x80001697  size 187 B
 * sha256  c1515ab8095f3be728b0aa23c234991954bdca3d080c1a03b57f7b4e0b3de2c8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_800015e0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x3c);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,param_3);
    puVar1[9] = iVar2;
    if (iVar2 == 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),puVar1);
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar1[10] = iVar2 + param_3;
      puVar1[0xd] = param_2;
      *puVar1 = 0;
      FUN_80001510(puVar1,param_1,puVar1 + 0xe);
      puVar3 = puVar1;
    }
  }
  return puVar3;
}
