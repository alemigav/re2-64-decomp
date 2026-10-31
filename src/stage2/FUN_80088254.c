/* FUN_80088254
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088254  body 0x80088254..0x800882d3  size 131 B
 * body sha256 e1689c99430537a22d783241588ee5e31e21fb1dfc9cb3a7a47f6e72a640b395
 * provider record sha256 b573020e6a90f308ab9dccf42254f20bb55cd494d32894f09355b10ff5c98789
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
