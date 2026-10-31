/* FUN_8006f3b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f3b4  body 0x8006f3b4..0x8006f447  size 151 B
 * sha256  585b92e3f66fa7e2628a89b8259238336abbf67811a9c9dadb70a96120c0ebe7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f3b4(int param_1)

{
  byte *pbVar1;
  
  DAT_801152cc = (byte *)(&DAT_800dfb60)[*(byte *)(*(int *)(param_1 + 0x1c) + 1)];
  pbVar1 = DAT_801152cc + 0x14;
  if ((DAT_801152cc[1] & 0x80) == 0) {
    pbVar1 = DAT_801152cc + 0xc;
  }
  (*(code *)(&PTR_LAB_80115290)[*DAT_801152cc])(pbVar1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
