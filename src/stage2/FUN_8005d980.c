/* FUN_8005d980
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d980  body 0x8005d980..0x8005d9a3  size 39 B
 * body sha256 2e546e559f05493cfa6d3dedcc672580b6505890b5b12b1b41d06a601cb55d32
 * provider record sha256 7db98965fd081f8b584208efb80e67fc3be3c1f3c9efbb9b3543896ffa9cd9d7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d980(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
