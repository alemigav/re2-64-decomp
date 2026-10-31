/* FUN_8008c33c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c33c  body 0x8008c33c..0x8008c39f  size 103 B
 * body sha256 c059c54497537946928417939c7608950bbb30f31f46737ee9bd792c1ab87efd
 * provider record sha256 8431d374cc3fa6d32a273b49a76cd0ac35f8acc6ebac4b818fede136091e7a29
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c33c(int param_1,undefined1 param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_1 * 4;
  cVar2 = (&DAT_800e8eca)[iVar1];
  if (cVar2 == '\x01') {
    (&DAT_800e8ec9)[(param_1 + 1) * 4] = param_2;
    cVar2 = (&DAT_800e8eca)[iVar1];
  }
  if (cVar2 == '\x02') {
    (&DAT_800e8ec9)[(param_1 + -1) * 4] = param_2;
  }
  (&DAT_800e8ec9)[iVar1] = param_2;
  return;
}
