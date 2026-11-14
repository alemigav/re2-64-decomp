/* FUN_801805f0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801805f0  body 0x801805f0..0x801806cb  size 220 B
 * body sha256 882d370baf10b6d7559bc580b6dea9dcbc9e7744f9948915f0ba1f90ad332ee9
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (54 of 55 -> 55 of 55) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/801805f0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned char DAT_80119e74;
extern unsigned int _DAT_800c52dc;














undefined4 FUN_801805f0(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  func_0x80004cfc(param_1,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0,0);
  func_0x800752dc(param_2,8,1);
  uVar1 = func_0x800a8bc8(param_2,param_3,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0);
  func_0x800a2218(((uint)DAT_80119e74 * 0x7f) / 100 & 0xff,0,uVar1,0);
  return uVar1;
}
