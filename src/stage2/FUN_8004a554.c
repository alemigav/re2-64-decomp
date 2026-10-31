/* FUN_8004a554
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a554  body 0x8004a554..0x8004a5b3  size 99 B
 * sha256  69084ace851911536b49ac68ea21c1b9cad0ca1205208aafd2c86ed309dda055
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a554(void)

{
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [16];
  
  FUN_8004a23c(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,auStack_28,DAT_800e10f1,
               (int)DAT_800e10f2);
  FUN_80082d4c(auStack_24,auStack_18);
  return;
}
