/* FUN_800879a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800879a0  body 0x800879a0..0x800879cf  size 51 B
 * body sha256 5d69682140c64d8ae514c49e88472fff7f7ed401f29362aba893ca4b2ce09e64
 * provider record sha256 9635c55c26efde39f9edbc56db1f45c15c734a9e845e2ac5ac8367624aebc359
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800879a0(undefined4 param_1)

{
  osSendMesg(0x8013a230,param_1,0);
  func_0x80011390();
  return;
}
