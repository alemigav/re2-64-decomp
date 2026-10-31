/* FUN_80034d3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80034d3c  body 0x80034d3c..0x80034e0b  size 211 B
 * sha256  5f96a23ca0f350de706769aed5da86d8d1bf73523599b9582eef8a8a63ea0582
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80034d3c(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_78 [96];
  
  iVar2 = *(int *)(param_1 + 0x234);
  FUN_80040e58(param_1 + 100,param_1 + 0x14);
  FUN_800424ec(param_1 + 0x14,iVar2 + 8,auStack_78);
  uVar1 = *(ushort *)(param_1 + 0x66);
  *(ushort *)(iVar2 + 0x5c) = *(ushort *)(iVar2 + 0x5c) & 0xfff;
  FUN_800352c4(iVar2 + 0xd38,auStack_78,400,0,0x28,4,0,400,0,0x18,4,0,
               (int)(((uint)uVar1 + (uint)*(ushort *)(iVar2 + 0x5a)) * 0x10000) >> 0x10);
  return;
}
