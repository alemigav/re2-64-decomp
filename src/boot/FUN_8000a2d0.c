/* FUN_8000a2d0
 * image   boot (boot), base 0x80000480
 * address 0x8000a2d0  body 0x8000a2d0..0x8000a393  size 199 B
 * sha256  2d0cc26749e86ebe6138eff82e5446a30683cf6fdd3c8327b7e6c9b518f908e7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a2d0(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char local_28 [32];
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    iVar1 = FUN_8000a66c();
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_28);
  if ((iVar1 == 0) ||
     ((iVar1 == 2 &&
      (iVar1 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_28),
      iVar1 == 0)))) {
    iVar1 = 0;
    pcVar3 = local_28;
    do {
      iVar2 = param_1 + iVar1;
      iVar1 = iVar1 + 1;
      if (*(char *)(iVar2 + 0xc) != *pcVar3) {
        return 2;
      }
      pcVar3 = pcVar3 + 1;
    } while (iVar1 < 0x20);
    iVar1 = 0;
  }
  return iVar1;
}
