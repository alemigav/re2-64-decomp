/* FUN_8008c25c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c25c  body 0x8008c25c..0x8008c313  size 187 B
 * sha256  cc9dd42811a209b4e0610f87f12b5ad857eb270e880c1e79f5918bd8ae6fc7f1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c25c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_4 < 100) {
    uVar2 = (byte)(&DAT_8012ffa9)[param_4 * 8] & 0xf;
  }
  if ((uVar2 != 0) && (iVar1 = FUN_800837ac(&DAT_800e8d78,uVar2), iVar1 != 0)) {
    param_4 = uVar2 + 0x91;
  }
  FUN_8004bf6c(param_1,param_2,param_3 | 0x4000,param_4);
  return;
}
