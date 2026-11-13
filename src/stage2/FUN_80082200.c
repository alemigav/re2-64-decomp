/* FUN_80082200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082200  body 0x80082200..0x80082223  size 36 B
 * body sha256 48490e3f3ceff5998c9b5f9d8d7963724642ce75117b4df4f4687ec4e99373a4
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80082200.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;












void FUN_80082200(undefined1 *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + -1;
  if (param_3 != 0) {
    do {
      *param_1 = param_2;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}
