/* FUN_80089d54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089d54  body 0x80089d54..0x80089dc7  size 119 B
 * sha256  cb1a2c5084767627311041446b84aa5b6688bae624c2a9ccfaade9cab8ed5367
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089d54(int param_1,undefined4 param_2,int param_3,uint param_4)

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
  FUN_80089dc8(param_2);
  return;
}
