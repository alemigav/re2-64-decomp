/* FUN_80011390
 * image   boot (boot), base 0x80000480
 * address 0x80011390  body 0x80011390..0x800113d7  size 75 B
 * sha256  15cd151f8ba57f1d78067c754545dfd42d9b204fb01330b3f6ab34311c57c13c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80011390(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  *(undefined2 *)(_DAT_80012950 + 0x10) = 2;
  FUN_80000dd4(&DAT_80012948);
  FUN_80007300(uVar1);
  return;
}
