/* FUN_8017d460
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d460  body 0x8017d460..0x8017d523  size 196 B
 * body sha256 33dc94965b83fc5665f2e447e191650dc0baaae26bc36f51982de8a8c52e79f7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017d460.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_8018576c;
extern unsigned int DAT_80185770;
extern unsigned int DAT_80185774;
extern unsigned int DAT_80185778;
extern unsigned int DAT_8018577c;
extern unsigned int DAT_80186c94;












void FUN_8017d460(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_80186c94 + 0x42c) = 0;
  FUN_8017bec8(10);
  DAT_8018576c = FUN_8017bec8(3);
  FUN_8017bec8(0x10);
  if (DAT_8018576c - 2U < 2) {
    DAT_80185778 = FUN_8017bec8(1);
    iVar1 = FUN_8017bec8(3);
    DAT_80185770 = iVar1 + -1;
  }
  if (DAT_8018576c == 3) {
    DAT_8018577c = FUN_8017bec8(1);
    iVar1 = FUN_8017bec8(3);
    DAT_80185774 = iVar1 + -1;
  }
  FUN_8017dd78();
  FUN_8017d61c();
  return;
}
