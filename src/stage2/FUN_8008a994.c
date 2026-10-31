/* FUN_8008a994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008a994  body 0x8008a994..0x8008aa07  size 119 B
 * body sha256 61a4cccfd08c3129a90e025f4cc22e00d38e669845efecda9f3e3cd6f5bd8540
 * provider record sha256 a5e9318dfb454a06895e8038208ae4f7a5cbad1b23a788dca305471b7afdeb26
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008a994(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_3 + (uint)*(byte *)(param_1 + 0x1e8) * 4);
  if ((param_4 & 0xffff0000) == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x1e9);
  }
  else {
    uVar1 = ((uVar2 & 0xffff) - (uint)*(byte *)(param_1 + 0x1e9)) - 1;
  }
  *(uint *)(param_1 + 0x214) = param_3 + (uVar2 >> 0x10) + uVar1 * 4;
  FUN_8008aa08(param_2);
  return;
}
