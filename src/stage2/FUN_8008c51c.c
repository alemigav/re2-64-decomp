/* FUN_8008c51c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c51c  body 0x8008c51c..0x8008c567  size 79 B
 * sha256  72944c2041ac3edee4fbf71c8c671e098026c35521236419af0fde2126106ff2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008c51c(uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0;
  puVar2 = &DAT_800c76b0;
  do {
    if (*(byte *)(puVar2 + 0x8606) == param_1) {
      return uVar1;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < DAT_800e8b38);
  return 0xffffffff;
}
