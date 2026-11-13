/* FUN_8003b2a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b2a4  body 0x8003b2a4..0x8003b2db  size 56 B
 * body sha256 653d11a6f5f0546de10dd2434064b75f797bfb49a377672b685d763977d6f581
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003b2a4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_800e9028;
extern unsigned int DAT_800ebb94;












void FUN_8003b2a4(void)

{
  FUN_80038a20(0x30a1800,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  return;
}
