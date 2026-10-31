/* FUN_8007ef94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ef94  body 0x8007ef94..0x8007efe7  size 87 B
 * sha256  6a348114427afd552331c12ee73d04645d14d950564803b977d05700337f90dd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ef94(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),0xa0);
  }
  return;
}
