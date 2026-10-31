/* FUN_80002b8c
 * image   boot (boot), base 0x80000480
 * address 0x80002b8c  body 0x80002b8c..0x80002bb3  size 43 B
 * sha256  592415d339964b58ec233858a94f73b3185d98089a9806766d70cd27a0314937
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002b8c(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}
