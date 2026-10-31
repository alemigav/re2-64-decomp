/* FUN_8004afbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004afbc  body 0x8004afbc..0x8004b0a7  size 239 B
 * sha256  20ac73fb8d700039271cf89724648b67b24d3c87d79ba2a991457c787d64d67f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8004b018) */
/* WARNING: Removing unreachable block (ram,0x8004b04c) */

void FUN_8004afbc(void)

{
  uint uVar1;
  
  if ((DAT_8010b294 & 0x80) != 0) {
    FUN_8004b0a8(&DAT_800fe288);
  }
  FUN_8004c4a0(&DAT_800fe288);
  uVar1 = (DAT_8010aa88 + 0x7ff01d78U) / 0x14;
  if (DAT_800fe27c < uVar1) {
    DAT_800fe27c = uVar1;
  }
  uVar1 = (DAT_8010aa8c + 0x7feff578U) / 0x14;
  if (DAT_800fe280 < uVar1) {
    DAT_800fe280 = uVar1;
  }
  if (DAT_800fe278 < DAT_8010b290 + 0x7fef5570U) {
    DAT_800fe278 = DAT_8010b290 + 0x7fef5570U;
  }
  FUN_8004c910();
  return;
}
