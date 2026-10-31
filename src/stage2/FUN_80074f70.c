/* FUN_80074f70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074f70  body 0x80074f70..0x80074fbb  size 79 B
 * sha256  2ba0a27b52a6c3420d1b2947e00dcc9c886113e7ed67d9dfae1c063f276c5af2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80074f70(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((DAT_800e110c & 8) != 0) || (uVar1 = 2, (DAT_800e110c & 4) != 0)) {
    FUN_80074fbc(uVar1);
  }
  return;
}
