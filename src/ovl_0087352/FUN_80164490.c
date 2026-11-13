/* FUN_80164490
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164490  body 0x80164490..0x80164503  size 116 B
 * body sha256 a95dcad02fdaade4ed7db5894177417d7c96c09ef5cced9b0cb1dbaa5de4247d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0087352/80164490.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef void code();
extern unsigned int DAT_800e1158;
extern unsigned int PTR_FUN_80166680;












void FUN_80164490(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  (*(code *)(&PTR_FUN_80166680)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
