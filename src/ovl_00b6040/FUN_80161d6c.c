/* FUN_80161d6c
 * image   ovl_00b6040 (ovl), base 0x80161cf0
 * address 0x80161d6c  body 0x80161d6c..0x80161deb  size 128 B
 * body sha256 bc9c65caac76ae03aff263ae99284fa733547c8d5e2ff6a3800983f4d0767e2d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b6040/80161d6c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_80161d6c(uint *param_1)

{
  param_1[1] = 0x2000000;
  param_1[0x7a] = 0;
  func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0);
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  param_1[0xa1] = 0;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  *(undefined1 *)(param_1[0x82] + 0xe) = 0;
  *param_1 = *param_1 | 10;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  return;
}
