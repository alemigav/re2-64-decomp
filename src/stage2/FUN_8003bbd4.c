/* FUN_8003bbd4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bbd4  body 0x8003bbd4..0x8003bd83  size 435 B
 * sha256  63c0dea8b74c40b6135ce1f92a1a892571a5c8bc2ed252c03bf426c8506bd978
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bbd4(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar3 = FUN_80060f78(&local_20,800,0x14);
  iVar2 = DAT_800ebb94;
  if (iVar3 == 0) {
    if (*(char *)(DAT_800ebb94 + 0x1b) < '\x14') {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      *(char *)(DAT_800ebb94 + 0x1b) = *(char *)(DAT_800ebb94 + 0x1b) + '\x01';
      *(ushort *)(iVar2 + 4) = *puVar1 + (short)(((uint)*puVar1 * 0x26) / 1000);
    }
    *(short *)(DAT_800ebb94 + 6) =
         (short)((longlong)(int)(uint)*(ushort *)(DAT_800ebb94 + 6) * 0x4051eb851f >> 0x26);
  }
  else {
    if (*(byte *)(iVar3 + 8) < 0x10) {
      if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
        DAT_800e13e4 = 0x1518;
        DAT_800e13e6 = 0x1e;
        DAT_800e139f = DAT_800e139f | 0x80;
      }
      FUN_80052bd0(8,0);
      FUN_80052d10(0xe,0xb4,0x3c,0);
    }
    else if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
      DAT_800e900f = DAT_800e900f | 1;
    }
    (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
  }
  return;
}
