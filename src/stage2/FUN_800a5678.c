/* FUN_800a5678
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5678  body 0x800a5678..0x800a56bf  size 75 B
 * body sha256 6632bd83aaa51b2124fc8834187e6b2f986bfbd0ffe9801a77d0768d6c9f5d1e
 * provider record sha256 fc8c20df6e1937abf28ba22162020347ac9ceddfce1af12d89f6ce9edba40db2
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
