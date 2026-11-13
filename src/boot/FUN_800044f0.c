/* FUN_800044f0
 * image   boot (boot), base 0x80000480
 * address 0x800044f0  body 0x800044f0..0x8000454f  size 96 B
 * body sha256 608144db506f4624a44cc666b610cc13e7811deb96fda9a564c70f3138a6f8f1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/800044f0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int _DAT_80012820;
extern unsigned int _DAT_8010b6f8;














int FUN_800044f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_80012820;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (iVar1 == 0) {
    _DAT_80012820 = _DAT_8010b6f8;
  }
  FUN_800013b0(_DAT_80012820);
  uVar2 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return param_1;
}
