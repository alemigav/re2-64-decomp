/* FUN_800a56c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a56c0  body 0x800a56c0..0x800a56ff  size 67 B
 * sha256  a855de136745ac8eb61f022b03f7f8d87d233d5b88a252847a509efa07cf3a3d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a56c0(void)

{
  if ((0 < DAT_80135cac) && (DAT_80135cac = DAT_80135cac + -1, DAT_80135cac == 0)) {
    osSendMesg(0x80143fb0,0,0);
  }
  return;
}
