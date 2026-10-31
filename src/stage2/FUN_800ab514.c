/* FUN_800ab514
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab514  body 0x800ab514..0x800ab573  size 99 B
 * body sha256 12f4ff4e37bf4c2321265dcdee05a6652b5563747bacb9e00e47bf18d51b3735
 * provider record sha256 ae0b7cb13c80b8b3f0e622866878efd181685187058718d3e5fb1699fcc038ad
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab514(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_800a84e8(param_2);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  *param_1 = ((*param_1 << 0x10) / uVar1) * 1000 >> 5;
  return;
}
