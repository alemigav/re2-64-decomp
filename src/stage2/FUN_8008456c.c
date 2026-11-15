/* FUN_8008456c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008456c  body 0x8008456c..0x8008457b  size 16 B
 * body sha256 b69957c24cf5eed7537c3dd515208e19428ca7295a588e02041105c168e5cb41
 * recovered byte-exact (read from the words (M448): the image materialises `&DAT_8011c924` once into v0 and stores it to `0x7800(v0)`, i.e. it expresses 0x80124124 as a DISPLACEMENT of the source symbol rather than loading a second symbol (Ghidra's `DAT_80124124 = &DAT_8011c924` costs an extra `lui`). Binding the address to a local and reusing it is what makes gcc keep one register and one `lui`.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8008456c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_8011c924;
extern unsigned int DAT_80124124;












void FUN_8008456c(void)

{
  unsigned int p;
  p = (unsigned int)&DAT_8011c924;
  *(unsigned int *)(p + 0x7800) = p;
  return;
}
