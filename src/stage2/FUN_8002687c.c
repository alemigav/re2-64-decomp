/* FUN_8002687c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002687c  body 0x8002687c..0x800268bb  size 67 B
 * body sha256 d577e3dfd4a355ce9815dba778d4824a54fcc40b3ad65f86c4b3fb2b5becea4e
 * provider record sha256 76f849c63a5498ee1faa27dd54df035f795a49ac3c8889df9f0552c650463f41
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
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
