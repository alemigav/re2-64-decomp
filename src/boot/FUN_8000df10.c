/* FUN_8000df10
 * image   boot (boot), base 0x80000480
 * address 0x8000df10  body 0x8000df10..0x8000df63  size 87 B
 * sha256  520a7d85575a3c56c9ce7669b6c7d13d74b2d177ae63b670e35cd2a210b817ea
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000df10(void)

{
  int iVar1;
  
  iVar1 = _DAT_80012960;
  _DAT_80017828 = 0;
  _DAT_8001782c = 0;
  _DAT_80017820 = 0;
  _DAT_80017824 = 0;
  *(undefined4 *)(_DAT_80012960 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 4) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}
