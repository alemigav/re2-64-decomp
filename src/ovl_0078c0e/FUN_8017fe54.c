/* FUN_8017fe54
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017fe54  body 0x8017fe54..0x8017feb7  size 100 B
 * body sha256 285e803181fb2564fc6ec96fec62c761c4615420056feea0fee914aa72753f32
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0078c0e/8017fe54.c
 * extents and pins: fixtures/decomp/recovered.json
 */
enum { false = 0, true = 1 };












int FUN_8017fe54(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_s1;
  
  iVar2 = 3;
  FUN_8017f844();
  while( true ) {
    iVar1 = FUN_80180020(param_1 << 4);
    iVar2 = iVar2 + -1;
    if ((iVar1 != 0) && (unaff_s1 = FUN_8017ff0c(), unaff_s1 == 0)) break;
    if (iVar2 == 0) {
      return unaff_s1;
    }
  }
  return 0;
}
