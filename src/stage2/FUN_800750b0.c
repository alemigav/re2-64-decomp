/* FUN_800750b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800750b0  body 0x800750b0..0x8007513f  size 147 B
 * body sha256 fdf7615b3eb0fbaf807ae4bdd5e5c67b51165f9115652a6d52d493b3a0697563
 * provider record sha256 1ac38fc16f6010418c745abae94594e0fd86ec9e1fdd4bf39c445431e6de08a4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800750b0(short param_1)

{
  if (param_1 != 0) {
    DAT_8011a28f = DAT_80119e73;
  }
  FUN_800b2098((int)((uint)DAT_80119e73 * (uint)DAT_80119e7c) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (uint)DAT_80119e7c) >> 7 & 0xff,0,1,0);
  return;
}
