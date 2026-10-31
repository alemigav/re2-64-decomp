/* FUN_80000f60
 * image   boot (boot), base 0x80000480
 * address 0x80000f60  body 0x80000f60..0x80001053  size 247 B
 * sha256  fd8a03cb4793fc960ac73b2fd1ddd36b7918e19ab29e69a50fee8ea208213ebb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80000f60(void)

{
  int iVar1;
  
  iVar1 = FUN_80000f50(&DAT_80012948);
  _DAT_80012950 = iVar1;
  *(undefined2 *)(iVar1 + 0x10) = 4;
  setCopReg(0,Status,*(uint *)(iVar1 + 0x118) & 0xffff00ff |
                     *(uint *)(iVar1 + 0x118) & 0xff00 & _DAT_800128d0 & 0xff00);
  if ((_DAT_80012140 != 0) && (_DAT_80012140 < _DAT_80012144)) {
    *(int *)(_DAT_80012140 + 0xc) = iVar1;
    *(undefined4 *)(_DAT_80012140 + 8) = 2;
    *(undefined4 *)(_DAT_80012140 + 4) = Count;
    _DAT_80012140 = _DAT_80012140 + 0x10;
  }
  if ((*(int *)(iVar1 + 0x18) == 0) || ((*(uint *)(iVar1 + 0x118) & 0x4000000) == 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
