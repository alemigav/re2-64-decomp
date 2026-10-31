/* FUN_801679c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801679c8  body 0x801679c8..0x801679f3  size 47 B
 * sha256  01a719c01f4d9455019d6a1d2b241d885f5ae24af2e2de494fb713a855ea5265
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801679c8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  do {
    uVar2 = uVar2 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = param_2;
    iVar1 = iVar1 + 0x178;
  } while (uVar2 < 0x14);
  return;
}
