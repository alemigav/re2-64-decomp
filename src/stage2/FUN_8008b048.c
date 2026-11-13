/* FUN_8008b048
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b048  body 0x8008b048..0x8008b09b  size 84 B
 * body sha256 95a00e16483eccb50b8ecc16c558cabaa52b9ccb3dbc4c9781e19ecb8e766317
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8008b048.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












undefined4 FUN_8008b048(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = func_0x8000cd40(1);
  if (param_1 == 0) {
    param_1 = 1;
  }
  uVar2 = FUN_8008af80(param_1);
  func_0x8000cd40(uVar1);
  return uVar2;
}
