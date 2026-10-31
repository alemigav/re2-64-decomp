/* FUN_80163410
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163410  body 0x80163410..0x80163497  size 139 B
 * sha256  83ab3ac785761241e3efed4f35f34dc845b32095b3c25df5749f7a56e59564d4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163410(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    iVar3 = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2cc) = 1;
    do {
      uVar1 = uVar2 & 0xff;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar3 + 0x60) = 0x104010;
      FUN_80163bb8(param_1,uVar1,0);
      iVar3 = iVar3 + 0x178;
    } while (uVar2 < 3);
  }
  return;
}
