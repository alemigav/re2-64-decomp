/* FUN_8005c308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c308  body 0x8005c308..0x8005c32b  size 39 B
 * sha256  9e9b06e04a1da1051d25d41efc38ad88c0af9ae7e4c6dc65f766bd4daa9356a7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c308(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x1780;
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0x234) + 0x1d60;
  }
  *(undefined1 *)(iVar1 + 0x112) = 1;
  return;
}
