/* FUN_80041320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041320  body 0x80041320..0x80041453  size 311 B
 * sha256  4c61ec4ec800760c139a4fe0e90db9cff0a9686b8eea61d0e9d95e653d07f23e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80041320(undefined4 param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_800408c0();
  iVar5 = FUN_80040968(param_1);
  sVar1 = *(short *)(param_2 + 6);
  sVar2 = *(short *)(param_2 + 8);
  sVar3 = *(short *)(param_2 + 10);
  *(short *)(param_2 + 6) = (short)(sVar1 * iVar4 - *(short *)(param_2 + 0xc) * iVar5 >> 0xc);
  *(short *)(param_2 + 0xc) = (short)(sVar1 * iVar5 + *(short *)(param_2 + 0xc) * iVar4 >> 0xc);
  *(short *)(param_2 + 8) = (short)(sVar2 * iVar4 - *(short *)(param_2 + 0xe) * iVar5 >> 0xc);
  *(short *)(param_2 + 0xe) = (short)(sVar2 * iVar5 + *(short *)(param_2 + 0xe) * iVar4 >> 0xc);
  *(short *)(param_2 + 10) = (short)(sVar3 * iVar4 - *(short *)(param_2 + 0x10) * iVar5 >> 0xc);
  *(short *)(param_2 + 0x10) = (short)(sVar3 * iVar5 + *(short *)(param_2 + 0x10) * iVar4 >> 0xc);
  return;
}
