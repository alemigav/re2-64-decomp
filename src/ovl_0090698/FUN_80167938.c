/* FUN_80167938
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167938  body 0x80167938..0x801679c7  size 147 B
 * sha256  ba3a0ed949adb7b1497c4731c4bd1916e39bababad116e8261f239c31a549507
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167938(int param_1)

{
  undefined1 uVar2;
  int iVar1;
  
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    uVar2 = 10;
    if (*(short *)(param_1 + 0x1a8) == 0) {
      uVar2 = (&DAT_80168038)[*(byte *)(param_1 + 0x2d4)];
    }
    func_0x80077d18(uVar2,param_1);
    iVar1 = *(byte *)(param_1 + 0x2d4) + 1;
    *(char *)(param_1 + 0x2d4) = (char)iVar1 + (char)((ulonglong)(longlong)iVar1 / 3) * -3;
  }
  return;
}
