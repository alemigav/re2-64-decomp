/* FUN_80161db0
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161db0  body 0x80161db0..0x80161e1b  size 108 B
 * body sha256 6fe8fb9cc188c9f8fb9b9ebac8d25ee6346b880f6daa69e57ce1eeed5401b15c
 * recovered byte-exact (imported: the byte local must be int so `1 < b` is a SIGNED compare (slti, not sltiu) (M432))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009d282/80161db0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80161db0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(short *)(param_1 + 0x270) == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
  }
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + cVar2;
  return;
}
