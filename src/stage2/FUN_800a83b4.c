/* FUN_800a83b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a83b4  body 0x800a83b4..0x800a846f  size 191 B
 * body sha256 6084950a88da588b04786541e8064fe9396cd680c6e64b41853d4036465e9d59
 * provider record sha256 817a433bff765f451fd47541f5bb75c13187b2d3ffebf6b0d1e4c4ced0f63be8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a83b4(undefined2 param_1,char param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = FUN_800ae034(param_1);
  if (iVar1 != 0) {
    if (param_2 == -1) {
      param_2 = *(char *)(iVar1 + 6);
    }
    if (param_3 == -1) {
      param_3 = *(char *)(iVar1 + 7);
    }
    uVar2 = FUN_800a6820((uint)*(ushort *)(iVar1 + 2) << 0x10 | (uint)*(byte *)(iVar1 + 5) << 8 |
                         (uint)*(byte *)(iVar1 + 4),*(byte *)(iVar1 + 8) | 0x80,param_2,param_3,0xff
                         ,0xff,0,0xff,*(undefined1 *)(iVar1 + 9),0);
  }
  return uVar2;
}
