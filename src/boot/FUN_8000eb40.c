/* FUN_8000eb40
 * image   boot (boot), base 0x80000480
 * address 0x8000eb40  body 0x8000eb40..0x8000ec07  size 203 B
 * sha256  2035605f4b2f164fb0acb0e6a32b9202426b2a1c13d91dc6f95dfeb9f4b6fb5c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000eb8c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000eb40(undefined4 param_1)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  
  uVar3 = FUN_800072e0();
  puVar2 = _DAT_800129d4;
  uVar1 = *_DAT_800129d4;
  iVar4 = *(int *)(_DAT_800129d4 + 4);
  *(undefined4 *)(_DAT_800129d4 + 0xc) = param_1;
  *puVar2 = uVar1 | 2;
  fVar5 = *(float *)(puVar2 + 0xc) * (float)(*(uint *)(iVar4 + 0x20) & 0xfff);
  if (2.1474836e+09 <= fVar5) {
    fVar5 = fVar5 - 2.1474836e+09;
  }
  *(uint *)(puVar2 + 0x10) = (int)fVar5 & 0xfff;
  FUN_80007300(uVar3);
  return;
}
