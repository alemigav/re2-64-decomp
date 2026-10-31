/* FUN_80059c7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059c7c  body 0x80059c7c..0x80059ceb  size 115 B
 * body sha256 f80c3e485bdaffd70e23b28e2d75d9ef398e9e29f3f015175ef802ecf4e079b3
 * provider record sha256 57860bf08656d62f2c3861bc8eae13a82aea653365cc02d3633be1b50e7f5880
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
