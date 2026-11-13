/* FUN_801660b8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801660b8  body 0x801660b8..0x801660eb  size 52 B
 * body sha256 cf450be78145cedf7dffba530290790a4200bfe2b9b8df67e0af08a8c6d4a2f1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/801660b8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167fe0;












void FUN_801660b8(int param_1)

{
  (*(code *)(&PTR_FUN_80167fe0)[*(byte *)(param_1 + 6)])();
  return;
}
