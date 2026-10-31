/* FUN_80088254
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088254  body 0x80088254..0x800882d3  size 131 B
 * sha256  94d20d03a022a54c75f5fb34841531c6e871ec3a1d7e568b3bf51503bcfee56a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088254(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  if ((&DAT_8012a034)[param_1] == '\x02') {
    iVar1 = param_1 * 0x18;
    *(int *)(&DAT_8012a060 + iVar1) = param_1;
    *(undefined4 *)(&DAT_8012a074 + iVar1) = 0;
    *(undefined4 *)(&DAT_8012a064 + iVar1) = param_2;
    *(undefined4 *)(&DAT_8012a068 + iVar1) = param_3;
    *(undefined4 *)(&DAT_8012a06c + iVar1) = param_4;
    *(undefined4 *)(&DAT_8012a070 + iVar1) = param_5;
    *(undefined4 *)(&DAT_8012a040 + param_1 * 8) = 3;
    *(undefined **)(&UNK_8012a044 + param_1 * 8) = &DAT_8012a060 + iVar1;
    FUN_800879a0();
  }
  return;
}
