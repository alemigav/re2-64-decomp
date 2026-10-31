/* FUN_800a8364
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8364  body 0x800a8364..0x800a83b3  size 83 B
 * sha256  6f0d9c3bcc4a76e966b9457e6779bb016701bfeed647e18e5692e7c27c26feea
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a8364(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (param_1 & 0xff) * 0x28;
  uVar2 = 0;
  if ((((&DAT_80147ab4)[iVar1] != '\x04') && (uVar2 = 0, *(int *)(&DAT_80147aac + iVar1) != 0)) &&
     (uVar2 = 1, -1 < *(int *)(&DAT_80147aa8 + iVar1))) {
    uVar2 = 0;
  }
  return uVar2;
}
