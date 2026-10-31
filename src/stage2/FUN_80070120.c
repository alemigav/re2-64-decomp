/* FUN_80070120
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070120  body 0x80070120..0x800701d7  size 187 B
 * sha256  82c87690ab3eec5aa74c18e601e3408ebc3a071ca80085a9265fdc5e37bf668d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80070120(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = *(ushort *)(iVar2 + 2);
  uVar5 = (uint)*(short *)(iVar2 + 4);
  *(int *)(param_1 + 0x1c) = iVar2 + 6;
  uVar3 = FUN_800701d8(*(undefined4 *)(param_1 + 0x154),uVar1 >> 8);
  bVar4 = false;
  switch(uVar1 & 0xff) {
  case 0:
    bVar4 = uVar3 == uVar5;
    break;
  case 1:
    bVar4 = (int)uVar5 < (int)uVar3;
    break;
  case 2:
    bVar4 = (int)uVar5 <= (int)uVar3;
    break;
  case 3:
    bVar4 = (int)uVar3 < (int)uVar5;
    break;
  case 4:
    bVar4 = (int)uVar3 <= (int)uVar5;
    break;
  case 5:
    bVar4 = uVar3 != uVar5;
    break;
  case 6:
    bVar4 = (uVar3 & uVar5) != 0;
  }
  return bVar4;
}
