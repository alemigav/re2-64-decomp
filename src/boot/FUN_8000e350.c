/* FUN_8000e350
 * image   boot (boot), base 0x80000480
 * address 0x8000e350  body 0x8000e350..0x8000e3ab  size 95 B
 * sha256  080a48a47f09d527fa8539b854757ee8c02c40fc22b1ead73d6be02caefbef08
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e350(char param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar1 = FUN_800072e0();
  if (param_1 == '\0') {
    uVar2 = *_DAT_800129d4 & 0xffdf;
  }
  else {
    uVar2 = *_DAT_800129d4 | 0x20;
  }
  *_DAT_800129d4 = uVar2;
  FUN_80007300(uVar1);
  return;
}
