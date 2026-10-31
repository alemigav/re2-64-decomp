/* FUN_8008c33c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c33c  body 0x8008c33c..0x8008c39f  size 103 B
 * sha256  80dad2cedcd6b8bf2743619eea2dc961efa1efaac3589cea3ca1bcf710367140
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
