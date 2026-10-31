/* FUN_80038f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038f40  body 0x80038f40..0x80038f7b  size 63 B
 * body sha256 070872d61f3c41111a68736df4cbec2ee95c3e5dcf3b4ec86bbad22cdef96091
 * provider record sha256 c9965611f966c47ea063b5a30bbc95ba67315a64601fc6f42e3e8965d4e1e3e2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80038f40(uint param_1)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &UNK_800ebd2c;
  puVar1 = &DAT_800ebdc0;
  do {
    puVar2 = puVar2 + 0x7c;
    if (*(byte *)((int)puVar1 + 5) == param_1) {
      *(undefined1 *)((int)puVar1 + -0x17) = 0;
      *puVar2 = 0;
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 0x3e;
  } while (puVar2 != &DAT_800eebac);
  return 0;
}
