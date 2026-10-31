/* FUN_8008d2e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d2e4  body 0x8008d2e4..0x8008d36f  size 143 B
 * sha256  80545fda66eeb56285d5c44c9b3671b60f16591f4cc7d30fb38c2e1cbf6e04a3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8008d2e4(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_8012bec0;
  do {
    uVar2 = param_1 + 7U & 0xfffffff8;
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
    param_1 = func_0x80004cfc(uVar1,uVar2,0,&DAT_800b9ecc);
    param_1 = uVar2 + param_1;
  } while (iVar4 < 0x6a);
  return param_1;
}
