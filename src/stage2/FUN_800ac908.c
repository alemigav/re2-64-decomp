/* FUN_800ac908
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac908  body 0x800ac908..0x800ac927  size 32 B
 * body sha256 52157a25767ea5a57de9049484c0b9fd65452fe8b8a9778a36b989d5cba51b75
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800ac908.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












undefined2 FUN_800ac908(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_800ac394(param_1,param_1 + 0x10c);
  return uVar1;
}
