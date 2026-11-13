/* FUN_8017d9e4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d9e4  body 0x8017d9e4..0x8017da9b  size 184 B
 * body sha256 b2baa735432056620151027ddec0e4a0157b818bbf8602579390c190cf9be912
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017d9e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_801857c4;
extern unsigned int DAT_801857c8;
extern unsigned int DAT_801857cc;
extern unsigned int DAT_801857d0;
extern unsigned int DAT_801857d4;
extern unsigned int DAT_801857d8;
extern unsigned int DAT_80186c94;












void FUN_8017d9e4(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bec8(2);
  *(int *)(DAT_80186c94 + 0x420) = iVar1 + 1;
  FUN_8017bec8(4);
  if (*(int *)(DAT_80186c94 + 0x420) == 2) {
    DAT_801857c4 = FUN_8017bec8(0xe);
    FUN_8017bbe8(1);
    DAT_801857c8 = FUN_8017bec8(0xe);
    DAT_801857cc = FUN_8017bec8(5);
    DAT_801857d0 = FUN_8017bec8(5);
    DAT_801857d4 = FUN_8017bec8(5);
    DAT_801857d8 = FUN_8017bec8(5);
  }
  return;
}
