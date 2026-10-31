/* FUN_80038ff0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038ff0  body 0x80038ff0..0x8003901f  size 51 B
 * body sha256 be9e4fa8a1e9cde05faef38c120c168b960aabb6cca416f9f9081253c27b02d1
 * provider record sha256 e51b4d7572a32e9a8b5176f685dc393134a4bfe4b8f380dd3b894ec483368d71
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
