/* FUN_80036694
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036694  body 0x80036694..0x80036733  size 163 B
 * sha256  8b54fde3bd78b64076bd9e7b7cfc3c7fcef491bc313672f0005add87979c1d5f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036694(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_50 [64];
  
  uVar2 = param_1[0x8d];
  FUN_80083748(uVar2 + 0x4c);
  FUN_80042454(&DAT_800e9028,auStack_50);
  iVar1 = FUN_80083d2c(param_1 + 10,DAT_800df940);
  if ((iVar1 != 0) && ((*param_1 & 0x80000) == 0)) {
    FUN_800411b8(&DAT_800e9028,uVar2 + 0xd0);
    FUN_8008548c(uVar2,param_1 + 0x1e,0);
  }
  return;
}
