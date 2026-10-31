/* FUN_8007c4a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c4a8  body 0x8007c4a8..0x8007c5b3  size 271 B
 * sha256  245fa920f215c72c52737c298bdd4a240f54840013abff29b3a7e175429c7f08
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c4a8(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_8011b560;
  iVar2 = DAT_8011b54c;
  if ((param_2 & 0xf) == 10) {
    iVar2 = FUN_80080c68();
    if (iVar2 == 0) {
      return;
    }
    if (-1 < *(short *)(iVar2 + 0x1f2)) goto LAB_8007c50c;
    iVar2 = FUN_80080d64(param_1,iVar2);
  }
  if (iVar2 == 0) {
    return;
  }
LAB_8007c50c:
  iVar3 = (uint)*(ushort *)(iVar2 + 0x2e) - (uint)*(ushort *)(param_1 + 0x2e);
  if ((-1 < *(short *)(iVar2 + 0x1f2)) && (uVar1 < 0x5dc)) {
    iVar4 = iVar3 * 0x10000 >> 0x10;
    if ((-5000 < iVar4) && (iVar4 < 2000)) {
      uVar1 = *(ushort *)(param_1 + 0x1f0);
      *(undefined4 *)(param_1 + 4) = 0x1050000;
      *(int *)(param_1 + 0x250) = iVar2;
      *(ushort *)(param_1 + 0x1f0) = uVar1 & 0x1fff | 0x4000;
      if (iVar4 < -2000) {
        *(ushort *)(param_1 + 0x1f0) = uVar1 & 0x1fff | 0x8000;
      }
      if ((iVar3 + 499U & 0xffff) < 0x9c3) {
        *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x2000;
      }
    }
  }
  return;
}
