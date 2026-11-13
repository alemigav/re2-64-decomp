/* FUN_800438d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800438d4  body 0x800438d4..0x8004392f  size 92 B
 * body sha256 aa7c03dcd094facf1cb38ac21a90e53ece93e272caaf34211bb6b18e1e25f87a
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800438d4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_800efd94;
extern unsigned int DAT_800efd9c;












undefined4 FUN_800438d4(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x10) {
    param_1 = FUN_80043930(param_1,param_2);
  }
  return param_1;
}
