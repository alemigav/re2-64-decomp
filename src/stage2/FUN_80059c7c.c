/* FUN_80059c7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059c7c  body 0x80059c7c..0x80059ceb  size 115 B
 * sha256  3519577ec1d01f5e478612cd6a1a980c77f6125c6b113e9dc51364e1902c64d0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059c7c(uint *param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  *param_1 = *param_1 & 0xfffffffb;
  (**(code **)(&DAT_800df948 + (*(byte *)(param_1[0x94] + 8) - 0x10) * 4))
            (param_1,param_1[0x89],param_1[0x8a]);
  return;
}
