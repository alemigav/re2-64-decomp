/* FUN_800a5678
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5678  body 0x800a5678..0x800a56bf  size 75 B
 * sha256  75fd629415a39a03e9a7f5096b3e4d4fac2920d727e93b3d43ceccda43d57910
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5678(void)

{
  if (DAT_80135cac == 0) {
    osRecvMesg(0x80143fb0,0,1);
  }
  DAT_80135cac = DAT_80135cac + 1;
  return;
}
