/* FUN_8007608c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007608c  body 0x8007608c..0x800761ab  size 291 B
 * sha256  81adf4f2efec4ddaa3fab3b73c908b79bebc9cda901179685e0434164c28eb6c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007608c(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_8004cd88(1);
  if (-1 < DAT_80119eac) {
    FUN_80075608(4,1);
    DAT_80119eac = -1;
  }
  iVar1 = (param_1 & 0xff) * 2;
  uVar2 = DAT_800c52dc + 0x3210U & 0xfffffff0;
  DAT_80119edc = uVar2;
  do {
    func_0x80004cfc(*(undefined2 *)(&DAT_80115fd8 + iVar1),uVar2,1,"CORE EDH");
    DAT_80119eac = FUN_800752dc(*(undefined2 *)(&DAT_80115f60 + iVar1),4,1);
    DAT_8011a2a4 = (&PTR_DAT_80115f88)[param_1 & 0xff];
    FUN_8004cd88(1);
  } while (DAT_80119eac == -1);
  return;
}
