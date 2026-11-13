typedef unsigned char undefined1;
typedef unsigned short undefined2;
extern unsigned int DAT_800ebb94;












void FUN_8003d454(void)

{
  FUN_8003ad94();
  *(undefined1 *)(DAT_800ebb94 + 1) = 0x38;
  *(undefined2 *)(DAT_800ebb94 + 0x46) = *(undefined2 *)(DAT_800ebb94 + 0x12);
  return;
}
