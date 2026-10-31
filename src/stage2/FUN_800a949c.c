/* FUN_800a949c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a949c  body 0x800a949c..0x800a94a3  size 11 B
 * body sha256 57e4836f963ebe773772218cbcdac0b473d960ad2432ddeddf52953a5155368f
 * provider record sha256 158d94ffe094c60096c6182027e101861acfa418c8651610efd5e63a88858107
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a949c(int param_1,uint param_2,uint param_3,uint param_4,byte param_5)

{
  if ((DAT_80136310 != '\0') && (param_1 != -1)) {
    FUN_800a5678();
    FUN_800a5a60(param_1,(param_2 & 0xff) << 0x10,(param_3 & 0xff) << 0x10,(param_4 & 0xff) << 0x10,
                 (uint)param_5 << 0x10);
    FUN_800a56c0();
  }
  return;
}
