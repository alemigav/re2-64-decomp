/* FUN_8000d9e0
 * image   boot (boot), base 0x80000480
 * address 0x8000d9e0  body 0x8000d9e0..0x8000dad7  size 251 B
 * body sha256 899171361d15dea68406b8a7fd202a7027cd6a9f21cde128a2a369f5997fe0b2
 * provider record sha256 8d2f375577c99b0772df663061df442344afe49633c1df26e349e97f0aa302f3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000d9e0(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((param_2 & 7) != 0) {
    FUN_8000c620(0x80011ce0,0x80011ce4,0x3a);
  }
  if ((param_3 & 7) != 0) {
    FUN_8000c620(0x80011ce0,0x80011ce4,0x3b);
  }
  if ((param_4 & 7) != 0) {
    FUN_8000c620(0x80011ce0,0x80011ce4,0x3c);
  }
  iVar1 = FUN_8000d9c0();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    _DAT_a4040000 = param_2;
    _DAT_a4040004 = FUN_8000e800(param_3);
    if (param_1 == 0) {
      piVar3 = (int *)&DAT_a404000c;
    }
    else {
      piVar3 = (int *)&DAT_a4040008;
    }
    *piVar3 = param_4 - 1;
    uVar2 = 0;
  }
  return uVar2;
}
