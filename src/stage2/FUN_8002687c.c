/* FUN_8002687c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002687c  body 0x8002687c..0x800268bb  size 64 B
 * body sha256 f5c00525f9aafe50ae4579e5322fb4c6f00cf60627b95bebdc1a56c0fcacea47
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (15 of 16 -> 16 of 16) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002687c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_800c56f4;
extern unsigned int DAT_8010b6e0;
extern unsigned int DAT_8010b6e4;












void FUN_8002687c(void)

{
  undefined4 uVar1;
  
  if (DAT_800c56f4 == '\0') {
    uVar1 = DAT_8010b6e4;
  }
  else {
    uVar1 = DAT_8010b6e0;
  }
  FUN_8006bf48(uVar1);
  return;
}
