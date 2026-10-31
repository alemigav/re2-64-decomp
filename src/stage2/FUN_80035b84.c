/* FUN_80035b84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035b84  body 0x80035b84..0x80035c07  size 135 B
 * sha256  5e0efa378b10413c95d9a2fbd1e94aa83485731269a5ee302852d918af50252b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035b84(int param_1)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  if (DAT_800e8ca8 < 3) {
    if ((DAT_800e110c & 0x2000000) == 0) {
      uVar2 = *(undefined1 *)(param_1 + 0x26a);
      puVar1 = &DAT_800e8d08;
    }
    else {
      uVar2 = *(undefined1 *)(param_1 + 0x26a);
      puVar1 = &DAT_800e8d28;
    }
  }
  else {
    uVar2 = *(undefined1 *)(param_1 + 0x26a);
    puVar1 = &DAT_800e8d28;
  }
  FUN_80083758(puVar1,uVar2);
  return;
}
