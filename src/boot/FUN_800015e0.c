/* FUN_800015e0
 * image   boot (boot), base 0x80000480
 * address 0x800015e0  body 0x800015e0..0x80001697  size 187 B
 * body sha256 a7bbbdc39a9bd07cdd6b86b85dd5a665579a99a35a8c75bd95b19ed7f72c9c92
 * provider record sha256 50e52e9b4fa7c1f3773d13b87c2f8c32b6e399e9ccaaa7d7a9b06282a995241f
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
