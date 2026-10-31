/* FUN_80059cec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059cec  body 0x80059cec..0x80059d5b  size 115 B
 * body sha256 b78486e666dcc746d77da9a10d901313344b72a3ab6117d33ee2d931e7e77ef4
 * provider record sha256 44996cb50a8e7d4efd25659ba044148c4e77fa74671e46a84b8c37d9da9499d8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059cec(uint *param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  *param_1 = *param_1 & 0xfffffffb;
  (**(code **)(&DAT_800dfa48 + (*(byte *)(param_1[0x94] + 8) - 0x10) * 4))
            (param_1,param_1[0x89],param_1[0x8a]);
  return;
}
