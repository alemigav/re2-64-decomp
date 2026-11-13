/* FUN_80166584
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166584  body 0x80166584..0x801665b7  size 52 B
 * body sha256 3383b084f34994dd111a11f681f0c3d959d42439e3e7b6d03cb5dcf8a0526681
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80166584.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_LAB_801673a8;












void FUN_80166584(int param_1)

{
  (*(code *)(&PTR_LAB_801673a8)[*(byte *)(param_1 + 0x2c6)])(param_1,param_1 + 0x2b4);
  return;
}
