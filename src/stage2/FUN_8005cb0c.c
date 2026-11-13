/* FUN_8005cb0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cb0c  body 0x8005cb0c..0x8005cb3f  size 52 B
 * body sha256 d086794c44affa42f32cce1b962b65cc25e6de066b7f53441cd217f36ee9dd3f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8005cb0c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801110e0;












void FUN_8005cb0c(int param_1)

{
  (*(code *)(&PTR_FUN_801110e0)[*(byte *)(param_1 + 6)])();
  return;
}
