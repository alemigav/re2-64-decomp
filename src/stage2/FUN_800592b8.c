/* FUN_800592b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800592b8  body 0x800592b8..0x800593cf  size 283 B
 * sha256  a442643c10ca16af713618c611c54ceea8f1788ad962346f6fdeeb5c9f96cf86
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800592b8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        FUN_800551e0();
        param_1[1] = 0x1000000;
        *(undefined1 *)((int)param_1 + 0x26f) = 0;
        *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
        *(ushort *)(param_1 + 0x7c) = *(ushort *)(param_1 + 0x7c) | 2;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    param_1[0x7a] = 0x5000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x78] = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    uVar3 = 0x4010000;
    if (*(char *)((int)param_1 + 5) == '\0') {
      uVar3 = 0x4000000;
    }
    FUN_80077adc(uVar3 | 1,param_1 + 10);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    *param_1 = *param_1 & 0xfffffffb;
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x400);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  return;
}
