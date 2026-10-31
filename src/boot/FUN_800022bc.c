/* FUN_800022bc
 * image   boot (boot), base 0x80000480
 * address 0x800022bc  body 0x800022bc..0x80002313  size 91 B
 * sha256  79dec836330544721dd5dae4d467c0f4bdaa9845a9c0faec731e0fa3f2aef71b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800022bc(int param_1,int param_2)

{
  FUN_80001510();
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_1 + 0x24));
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return 0;
}
