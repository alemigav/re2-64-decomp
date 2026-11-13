/* FUN_80165f80
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165f80  body 0x80165f80..0x80165fef  size 112 B
 * body sha256 26dadae4b62a35721fa0ad49784ee4beffd5987da3dda5656e98448c784cbbd8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0087352/80165f80.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned char byte;
typedef unsigned short ushort;












void FUN_80165f80(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if ((*(ushort *)(param_1 + 0x2c6) & 0x10) != 0) {
    FUN_80166294(param_1,0x15e);
    bVar1 = func_0x80033604();
    *(byte *)(param_1 + 700) = bVar1 & 0x9d;
    uVar2 = func_0x80065628();
    *(undefined1 *)(param_1 + 699) = uVar2;
    *(undefined1 *)(param_1 + 0x2b8) = 0x1e;
    FUN_80165c68(param_1,4);
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xffa7;
  }
  return;
}
