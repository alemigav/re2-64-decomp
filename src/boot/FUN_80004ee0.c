/* FUN_80004ee0
 * image   boot (boot), base 0x80000480
 * address 0x80004ee0  body 0x80004ee0..0x80004f7f  size 163 B
 * body sha256 45199f42b765c223f5917fd3b277fc1c2f5bc3af046dc85add5f1ebdb632847e
 * provider record sha256 00911c9d245731a41484c54a2fc79cb2b678f80617f835bdb5fea230f9b5aec1
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
