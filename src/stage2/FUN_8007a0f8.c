/* FUN_8007a0f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a0f8  body 0x8007a0f8..0x8007a24f  size 347 B
 * sha256  cfd99b097ef48c2069cc9b21a7ffd400fc67db476b16c0fc0cb5d0b3c23cf2c2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a0f8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x1608) = 0;
  *(undefined4 *)(iVar1 + 0x166c) = *(undefined4 *)(iVar1 + 100);
  *(undefined4 *)(iVar1 + 0x1734) = *(undefined4 *)(iVar1 + 300);
  *(undefined4 *)(iVar1 + 0x1624) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x1628) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined2 *)(iVar1 + 0x1660) = 0;
  *(undefined2 *)(iVar1 + 0x1662) = 0;
  *(undefined2 *)(iVar1 + 0x1664) = 0;
  *(undefined4 *)(iVar1 + 0x162c) = *(undefined4 *)(iVar1 + 0x24);
  FUN_80040e58(iVar1 + 0x1660,iVar1 + 0x1610);
  FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,0);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(*(int *)(iVar1 + 0x120) + 0xc) = 0;
  FUN_80066288(param_1,iVar1);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(*(int *)(iVar1 + 0x1728) + 0xc) = 0;
  FUN_80066288(param_1,iVar1 + 0x1608);
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    if ((DAT_800e9012 & 8) != 0) {
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x234) + 0x120) + 0xc) = 0x1000;
      FUN_80066288(param_1);
      iVar1 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar1 + 0x1608) = *(uint *)(iVar1 + 0x1608) | 1;
      *(undefined2 *)(*(int *)(iVar1 + 0x1728) + 0xc) = 0x1000;
      FUN_80066288(param_1,iVar1 + 0x1608);
    }
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x100;
  }
  return;
}
