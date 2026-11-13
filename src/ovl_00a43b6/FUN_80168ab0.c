/* FUN_80168ab0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80168ab0  body 0x80168ab0..0x80168ae3  size 52 B
 * body sha256 fb0c59b2a8fe69a339e3f50adccda2e26c8f2ae3747ea11e5d9beb7c3325cb3a
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a43b6/80168ab0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801698d0;












void FUN_80168ab0(int param_1)

{
  (*(code *)(&PTR_FUN_801698d0)[*(byte *)(param_1 + 5)])();
  return;
}
