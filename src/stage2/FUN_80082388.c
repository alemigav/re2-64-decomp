/* FUN_80082388
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082388  body 0x80082388..0x800823af  size 40 B
 * body sha256 7c3c26abf6f97f9d5263d9acaf5fd64d5d4737e173aa503f28529dcc7f201dce
 * recovered byte-exact (imported: closed by the order:past-guard mechanism (M417, workbench))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80082388.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
int FUN_80082388(char *param_1)
{
  char cVar1;
  int iVar2;

  if (param_1 == (char *)0x0) {
    return 0;
  }
  iVar2 = 0;
  while (cVar1 = *param_1, param_1 = param_1 + 1, cVar1 != '\0') {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}
