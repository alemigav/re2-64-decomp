/* FUN_800844cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844cc  body 0x800844cc..0x800844e3  size 27 B
 * sha256  cdd60f48aaa88e00431eded056b229d8b231502bc5d1d6d6ab60e46708e1b49f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800844cc(uint param_1)

{
  return (param_1 & 0xff) << 8 | (param_1 & 0xffff) >> 8;
}
