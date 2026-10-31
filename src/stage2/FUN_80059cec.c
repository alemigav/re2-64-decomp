/* FUN_80059cec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059cec  body 0x80059cec..0x80059d5b  size 115 B
 * sha256  f743fd4c2f6e9735c225a2ad86f5ae83b4ca8180972b878a90a1010e07f6fc1b
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
