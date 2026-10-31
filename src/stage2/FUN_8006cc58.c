/* FUN_8006cc58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cc58  body 0x8006cc58..0x8006cccb  size 119 B
 * body sha256 488d806d17b61e0b42383de9dc675ee7d0f56ae17600265ca87bcc21cef7eae1
 * provider record sha256 37cb27ef291b34749d4a834b389a2d4bb21918f47ecaeb5cf6a6874244cf2d1c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cc58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) =
       ((int)((*(uint *)(param_1 + 0x1c) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x1c) & 0xffff) + param_2) % 0xffff;
  return;
}
