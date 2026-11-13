/* FUN_80032f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032f64  body 0x80032f64..0x80032fab  size 72 B
 * body sha256 2aa15aa83c87548fed5c90574c6b1fb7cf61d85208a857207f0e85312649a6de
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80032f64.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef unsigned int uint;












int FUN_80032f64(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 + (param_2 - (uint)*(ushort *)(param_1 + 0x66)) & 0xfff;
  iVar2 = (int)(short)param_3;
  if ((int)uVar1 < iVar2 << 1) {
    return 0;
  }
  if (uVar1 < 0x801) {
    return iVar2;
  }
  return -iVar2;
}
