/* FUN_8003751c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003751c  body 0x8003751c..0x8003765b  size 323 B
 * sha256  615a91bfafb9fe3ec39d0a95542d5098dc3f23ca0b0d86aec415b7c7264a37f7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8003751c(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  do {
    bVar1 = *(byte *)(param_1 + uVar6);
    (&DAT_800ebb98)[uVar6 + param_3] = bVar1;
    uVar4 = (uint)bVar1;
    uVar6 = uVar6 + 1;
    if (uVar4 == 0xff) {
      return param_2;
    }
    puVar5 = (undefined4 *)(param_2 + 7 & 0xfffffff8);
    *(undefined4 **)(&DAT_800ebca8 + uVar4 * 4) = puVar5;
    iVar2 = func_0x80004cfc(*(undefined2 *)(&DAT_800ebb30 + uVar4 * 2),puVar5,1,&DAT_800b8700);
    *(undefined4 **)(&DAT_800ebba8 + uVar4 * 4) = puVar5;
    param_2 = (int)puVar5 + iVar2;
    uVar3 = FUN_800844e4(*puVar5);
    *(undefined4 **)(&DAT_800ebca8 + uVar4 * 4) =
         puVar5 + (uVar3 & 0xffff) * 2 + (uVar3 >> 0x10) + 2;
  } while (uVar6 < 8);
  return param_2 + 7 & 0xfffffff8;
}
