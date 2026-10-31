/* FUN_80031a20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031a20  body 0x80031a20..0x80031aaf  size 147 B
 * sha256  515b69da893b83ba0e60a621cd1c8cd299f040e801938e5c4a7d9ce40810d89d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80031a20(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = -1;
  iVar1 = 0x1d8;
  iVar5 = 0x1d9;
  while( true ) {
    iVar3 = iVar1 / 2;
    if ((*(uint *)(&DAT_800ea290 + iVar3 * 4) & 0x1fffffff) < param_1) {
      iVar4 = iVar3;
      iVar3 = iVar5;
    }
    if (iVar3 - iVar4 < 2) break;
    iVar1 = iVar3 + iVar4;
    iVar5 = iVar3;
  }
  uVar2 = 5;
  if (param_1 == (*(uint *)(&DAT_800ea290 + iVar3 * 4) & 0x1fffffff)) {
    uVar2 = *(uint *)(&DAT_800ea290 + iVar3 * 4) >> 0x1d;
  }
  return uVar2;
}
