extern unsigned int DAT_8011c924;
extern unsigned int DAT_80124124;












void FUN_8008456c(void)

{
  unsigned int p;
  p = (unsigned int)&DAT_8011c924;
  *(unsigned int *)(p + 0x7800) = p;
  return;
}
