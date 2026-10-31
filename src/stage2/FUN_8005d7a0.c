/* FUN_8005d7a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d7a0  body 0x8005d7a0..0x8005d873  size 215 B
 * sha256  2cd052846e8a464aa5b283437a3178910e2d3a8ade1dc3b19d3924dd9e47f03b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d7a0(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0xc0;
  (*(code *)(&PTR_FUN_80110fd8)[(*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1])
            (param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),DAT_800df914)
  ;
  if ((*(short *)(param_1 + 0x1e0) == 0) &&
     ((*(char *)(param_1 + 6) != '\0' || (*(char *)(param_1 + 0x1ea) == '\0')))) {
    FUN_80033680(param_1,0,
                 (byte)(&DAT_80110e24)
                       [(*(byte *)(param_1 + 8) & 1) +
                        ((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1) * 3] >> 7);
  }
  return;
}
