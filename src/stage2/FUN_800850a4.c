/* FUN_800850a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800850a4  body 0x800850a4..0x800850db  size 56 B
 * body sha256 3ad0f56d28a2e40c8211fce5e11867c9ea4e8d37c5440f30cba9097bcdf975d2
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800850a4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined;
typedef unsigned short undefined2;
extern unsigned int DAT_8011c924;












void FUN_800850a4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_8011c924;
  iVar2 = 0x300;
  do {
    *(undefined2 *)(puVar1 + 0x22) = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  FUN_8008456c();
  return;
}
