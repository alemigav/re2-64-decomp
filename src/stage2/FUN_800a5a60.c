/* FUN_800a5a60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a60  body 0x800a5a60..0x800a5acb  size 108 B
 * body sha256 1670f0d6ca0cf0fcc2a28605c7f2bba0f29015a7878eb3e9227cb511adc1f9fe
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5a60.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int _DAT_80143f0c;














void FUN_800a5a60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _DAT_80143f0c + param_1 * 0x68;
  FUN_800a5da0(iVar1 + 0x42,iVar1 + 0x40,param_2,param_3,param_4,iVar1 + 0x44,param_5,iVar1 + 0x46);
  return;
}
