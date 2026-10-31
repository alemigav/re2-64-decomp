/* func_800b24c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b24c4  body 0x800b24c4..0x800b2527  size 103 B
 * body sha256 5613daf04df9234eeacad81e7bf95b3ccc1e3077445b8dfb3326e141672e969e
 * provider record sha256 71b00a432875fab8ee0569dbf3202a11b74551b8b68826b592c87020ec7f3deb
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b24c4(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7854(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
