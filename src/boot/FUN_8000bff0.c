/* FUN_8000bff0
 * image   boot (boot), base 0x80000480
 * address 0x8000bff0  body 0x8000bff0..0x8000c0c3  size 215 B
 * body sha256 b3c557d1e2edb89d2ce810d307f138915be88c2e7e77acdd7129bd3d3ff93fb2
 * provider record sha256 74f80e5714eac5609ddd44d7604e91d84a952b12cb37f6459aefe9d9960f0484
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_8000bff0(void)

{
  undefined4 uVar1;
  uint local_18 [2];
  
  local_18[0] = 0;
  if (_DAT_8001768c != -0x50000000) {
    DAT_80017684 = 0;
    _DAT_8001768c = -0x50000000;
    FUN_8000c940(0,local_18);
    DAT_80017689 = 0;
    _DAT_80017690 = 0;
    DAT_80017688 = (undefined1)(local_18[0] >> 8);
    DAT_80017686 = (byte)(local_18[0] >> 0x10) & 0xf;
    DAT_80017685 = (undefined1)local_18[0];
    DAT_80017687 = (byte)(local_18[0] >> 0x14) & 0xf;
    FUN_80006650(0x80017694,0x60);
    uVar1 = FUN_800072e0();
    _DAT_80017680 = _DAT_8001290c;
    _DAT_8001290c = &DAT_80017680;
    FUN_80007300(uVar1);
  }
  return &DAT_80017680;
}
