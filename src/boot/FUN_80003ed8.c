/* FUN_80003ed8
 * image   boot (boot), base 0x80000480
 * address 0x80003ed8  body 0x80003ed8..0x80003f67  size 147 B
 * body sha256 e0ca6a8eeb4112ec9450a02062b42ea3611f3cbc758898ab36745510448a03a5
 * provider record sha256 5915e4cc61b3a0c3f549227807ff736d9b0109060bcf7f6db272a6edc3b2685e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80003ed8(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_800038f0(param_1,0x13,0x13,0,0,param_3,param_2,param_4);
  if (iVar1 == -3) {
    uVar2 = 0x800117d0;
  }
  else {
    if (iVar1 != -5) {
      return iVar1;
    }
    FUN_800042f4(*param_3,param_4);
    uVar2 = 0x800117f8;
  }
  *(undefined4 *)(param_4 + 0x18) = uVar2;
  return -3;
}
