/* FUN_800ab7e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab7e0  body 0x800ab7e0..0x800abad3  size 759 B
 * sha256  eae310a165cfc38a414eeac25d0d8f0e80ed3fa2f8a7c65bd8f1adff62bf067e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab7e0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  uVar2 = param_1 & 0xff;
  if (uVar2 < 0x40) {
    bVar4 = (byte)((param_4 & 0xffff) >> 7);
    if ((param_3 & 0xff) == 0xff) {
      *(byte *)((param_1 & 0x1f) + (param_2 & 0xff) * 0x86 + -0x7feb3080) = bVar4 & 0x7f;
    }
    else {
      *(byte *)((param_1 & 0x1f) + (param_2 & 0xff) * 0x86 + (param_3 & 0xff) * 0x860 + -0x7feb7380)
           = bVar4 & 0x7f;
    }
    uVar2 = param_1 & 0x1f | 0x20;
    bVar4 = (byte)param_4 & 0x7f;
    if ((param_3 & 0xff) == 0xff) {
      *(byte *)(uVar2 + (param_2 & 0xff) * 0x86 + -0x7feb3080) = bVar4;
      return;
    }
    *(byte *)(uVar2 + (param_2 & 0xff) * 0x86 + (param_3 & 0xff) * 0x860 + -0x7feb7380) = bVar4;
    return;
  }
  if ((param_1 + 0x80 & 0xff) < 2) {
    bVar4 = (byte)((param_4 & 0xffff) >> 7);
    if ((param_3 & 0xff) == 0xff) {
      *(byte *)((param_1 & 0xfe) + (param_2 & 0xff) * 0x86 + -0x7feb3080) = bVar4 & 0x7f;
    }
    else {
      *(byte *)((param_1 & 0xfe) + (param_2 & 0xff) * 0x86 + (param_3 & 0xff) * 0x860 + -0x7feb7380)
           = bVar4 & 0x7f;
    }
    if ((param_3 & 0xff) == 0xff) {
      iVar3 = -0x7feb3080;
      uVar2 = param_1 & 0xff | 1;
      iVar1 = (param_2 & 0xff) * 0x86;
    }
    else {
      iVar3 = -0x7feb7380;
      uVar2 = (param_1 & 0xff | 1) + (param_2 & 0xff) * 0x86;
      iVar1 = (param_3 & 0xff) * 0x860;
    }
    *(byte *)(uVar2 + iVar1 + iVar3) = (byte)param_4 & 0x7f;
    return;
  }
  bVar4 = (byte)((param_4 & 0xffff) >> 7);
  if ((param_3 & 0xff) == 0xff) {
    *(byte *)(uVar2 + (param_2 & 0xff) * 0x86 + -0x7feb3080) = bVar4 & 0x7f;
    return;
  }
  *(byte *)(uVar2 + (param_2 & 0xff) * 0x86 + (param_3 & 0xff) * 0x860 + -0x7feb7380) = bVar4 & 0x7f
  ;
  return;
}
