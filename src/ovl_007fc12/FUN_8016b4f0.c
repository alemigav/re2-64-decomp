/* FUN_8016b4f0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b4f0  body 0x8016b4f0..0x8016b523  size 52 B
 * body sha256 c8ba41a2a0a5a106843e95695b167895ea74208bddf3d9cb14046e97e11f7050
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007fc12/8016b4f0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016e838;












void FUN_8016b4f0(int param_1)

{
  (*(code *)(&PTR_FUN_8016e838)[*(byte *)(param_1 + 5)])();
  return;
}
