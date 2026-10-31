/* FUN_80084420
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084420  body 0x80084420..0x800844cb  size 175 B
 * sha256  5248ede9093d7d862d4ee8239593032d59223a84865257772961c76d7fb12c5f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80084420(void)

{
  if (DAT_800e9183 != '\x02') {
    if ((DAT_800e10ec & 0x20000000) == 0) {
      FUN_80026910(*(undefined2 *)
                    (DAT_800e8cac * 2 +
                    *(int *)((&PTR_PTR_8011c3b0)[DAT_800e8ca8] + DAT_800e8caa * 4)));
      FUN_80026a88();
    }
    else {
      DAT_800e10ec = DAT_800e10ec & 0xdfffffff;
    }
  }
  return;
}
