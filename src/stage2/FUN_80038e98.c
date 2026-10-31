/* FUN_80038e98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038e98  body 0x80038e98..0x80038f3f  size 171 B
 * sha256  8ee28accc900286e95f70657a926f41f511187b529d478cdf282999790ec5ca4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80038e98(char param_1,char param_2,int param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    puVar1 = &DAT_800ebda8;
    do {
      uVar2 = uVar2 + 1;
      if ((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) {
        puVar1[1] = 0;
        *puVar1 = 0;
        *(undefined2 *)(puVar1 + 0x18) = 0;
      }
      puVar1 = puVar1 + 0x7c;
    } while (uVar2 < 0x60);
    return 0;
  }
  puVar1 = &DAT_800ebda8;
  do {
    if (((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) &&
       (*(int *)(puVar1 + 0x6c) == param_3)) {
      puVar1[1] = 0;
      *puVar1 = 0;
      *(undefined2 *)(puVar1 + 0x18) = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0x7c;
  } while (uVar2 < 0x60);
  return 0;
}
