/* FUN_8007bc9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bc9c  body 0x8007bc9c..0x8007bd9b  size 259 B
 * sha256  4023b926c7e9df3f79f4d56b46ddafd931fc124a20c478d280ecbbf65a8815b7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bc9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar3;
  ushort uVar2;
  ushort uVar4;
  
  FUN_800807cc();
  cVar3 = DAT_8011af7f + -1;
  if (DAT_8011af7f == '\0') {
    bVar1 = *(byte *)(param_1 + 0x1ab);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xff00;
    uVar2 = FUN_80080af4(param_1,3000);
    uVar4 = *(ushort *)(param_1 + 0x2b8);
    uVar2 = *(ushort *)(param_1 + 0x1aa) | uVar2;
    *(ushort *)(param_1 + 0x1aa) = uVar2;
    *(ushort *)(param_1 + 0x2b8) = uVar4 & 0x7fff;
    if ((bVar1 & 0xf) != (uVar2 & 0xf)) {
      uVar4 = uVar4 & 0x7ffc;
      *(ushort *)(param_1 + 0x2b8) = uVar4;
      *(ushort *)(param_1 + 0x2b8) =
           uVar4 | (byte)(&DAT_8011af74)[*(ushort *)(param_1 + 0x1aa) & 0xf] | 0x8000;
    }
    cVar3 = '\x0f';
  }
  DAT_8011af7f = cVar3;
  (*(code *)(&PTR_FUN_8011af48)[*(ushort *)(param_1 + 0x1aa) & 0xf])(param_1,param_2,param_3);
  return;
}
