/* FUN_8005bdf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005bdf4  body 0x8005bdf4..0x8005be9f  size 175 B
 * sha256  197d6285684e5a3d913595363c0aab0096b2fcef636a188febc63e5d5466dd9c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005bdf4(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *param_1;
  iVar4 = (param_3 << 0x10) >> 0xd;
  *param_1 = uVar1 & 0x1fffffff;
  iVar3 = (int)(((int)*(short *)(&DAT_80110e74 +
                                ((char)(&DAT_80110f04)[*(byte *)(param_1 + 2)] + 2) * 2 + iVar4) +
                param_1[0xb]) * (int)*(short *)((int)param_1 + 0x27a)) >> 0xc;
  uVar2 = 0x80000000;
  if ((iVar3 + *(short *)(&DAT_80110e74 + iVar4) <= param_2) &&
     (uVar2 = 0x20000000, param_2 <= iVar3 + *(short *)(&DAT_80110e76 + iVar4))) {
    uVar2 = 0x40000000;
  }
  *param_1 = uVar1 & 0x1fffffff | uVar2;
  return;
}
