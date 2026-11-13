/* FUN_801623e4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801623e4  body 0x801623e4..0x80162443  size 96 B
 * body sha256 2a85c21d74b5f8a94f6486d312cdb909622789a7690dd7e4db49d2ac7917364d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/801623e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_801623e4(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(short *)(param_1 + 500) - 0x200;
  *(ushort *)(param_1 + 500) = uVar1;
  if ((int)((uint)uVar1 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  FUN_80167bd8(param_1,9,0,(int)*(short *)(param_1 + 500));
  FUN_80167bd8(param_1,6,0,(int)*(short *)(param_1 + 500));
  return;
}
