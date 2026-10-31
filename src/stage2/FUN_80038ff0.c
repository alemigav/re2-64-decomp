/* FUN_80038ff0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038ff0  body 0x80038ff0..0x8003901f  size 51 B
 * sha256  7c8d987c91d505f05f0c541f797a0cbeb9a9333264e232eba602ec554b999721
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80038ff0(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &UNK_800ebd2c;
  puVar1 = (undefined2 *)&UNK_800ebd44;
  do {
    puVar2 = puVar2 + 0x7c;
    *(undefined1 *)((int)puVar1 + 0x65) = 0;
    *puVar2 = 0;
    puVar1[0x3e] = 0;
    puVar1 = puVar1 + 0x3e;
  } while (puVar2 != &DAT_800eebac);
  return;
}
