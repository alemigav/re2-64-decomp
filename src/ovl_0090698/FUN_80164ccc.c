/* FUN_80164ccc
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164ccc  body 0x80164ccc..0x80164db7  size 236 B
 * body sha256 d5683aeaaecdada070194d239cd9edc113df5caaad6284240fdf24d6ad2fdf3c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80164ccc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164ccc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  func_0x80032bd8(param_1,0,(int)*(short *)(param_1 + 0x7d));
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  if (*(short *)(param_1 + 0x7d) != 0) {
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x200;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -0x200;
  }
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xefffffff | 0xc000000;
    if (*(short *)(param_1 + 0x7d) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      param_1[0x7a] = 0x9000300;
    }
    uVar1 = 5;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar1 = 6;
    }
    func_0x80077d18(uVar1,param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  return;
}
