/* FUN_8004fdf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fdf4  body 0x8004fdf4..0x8004fe4f  size 95 B
 * body sha256 6df7ccf1f7ded387bb83649a683862e916bfe9be024b30791f3b1a2df5accc06
 * provider record sha256 e9c8badb1762475a926f009cfc73ed887c525ffb2ecb6c5932b4616cc4039006
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8004fd3c::caseD_3
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,undefined1 *param_4)

{
  byte bVar1;
  
  if ((byte)param_4[2] == 0) {
    trap(0x1c00);
  }
  *param_2 = (short)((uint)(byte)param_4[1] / (uint)(byte)param_4[2] << 4);
  bVar1 = param_4[1] + 1;
  param_4[1] = bVar1;
  if ((uint)bVar1 == (uint)(byte)param_4[3] * (uint)(byte)param_4[2]) {
    param_4[1] = bVar1 - param_4[2];
    *param_4 = 0x84;
    return;
  }
  return;
}
