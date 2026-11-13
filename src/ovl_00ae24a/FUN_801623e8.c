/* FUN_801623e8
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623e8  body 0x801623e8..0x80162483  size 156 B
 * body sha256 4bc85eefca1e8516f78cc03795dcf13abe372a1e517a345864c7fd22276382f0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00ae24a/801623e8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80166f90;
extern unsigned int PTR_FUN_80166fa4;












void FUN_801623e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(ushort *)(param_1 + 0x2c2) & 6) == 4) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  else {
    (*(code *)(&PTR_FUN_80166f90)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_80166fa4)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
