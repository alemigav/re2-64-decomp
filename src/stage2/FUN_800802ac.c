/* FUN_800802ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800802ac  body 0x800802ac..0x8008039b  size 243 B
 * sha256  dab6a8e971e666a66b6ce2de885e47df89d5137eaf7e2f941cc1f0d2a0fd7572
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800802ac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        param_1[1] = 0x1000000;
        *(undefined1 *)((int)param_1 + 0x26f) = 0;
        *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    param_1[0x7a] = 0x5000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x78] = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    FUN_80077d18(0,param_1);
    *param_1 = *param_1 & 0xfffffffb;
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x400);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  return;
}
