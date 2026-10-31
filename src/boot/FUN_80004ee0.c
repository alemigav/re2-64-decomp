/* FUN_80004ee0
 * image   boot (boot), base 0x80000480
 * address 0x80004ee0  body 0x80004ee0..0x80004f7f  size 163 B
 * sha256  a35a74f53ce9e5ef5731190a8ef4cddc6a224e9cbda922c833f12328358ade2f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80004ee0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  
  if ((param_1 == 0xffff) || (param_1 == -1)) {
    uVar1 = 0;
  }
  else {
    piVar2 = (int *)(param_1 * 8 + _DAT_80012874);
    uVar1 = piVar2[1];
    if ((*piVar2 < 0) || (uVar1 == 0)) {
      trap(0);
    }
    if ((uVar1 & 1) != 0) {
      uVar1 = uVar1 + 1;
    }
    func_0x800888ec(_DAT_800128a8 + *(int *)(param_1 * 8 + _DAT_80012874) + param_3,param_2,param_4)
    ;
  }
  return uVar1;
}
