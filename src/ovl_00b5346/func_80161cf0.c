/* func_80161cf0
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161d83  size 151 B
 * sha256  7c1a32008f6bec7a5aed1dc05732d8f55697ee2c3ea5565064b67185b61e3842
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_80163020)[*(byte *)(in_a0 + 4)])();
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
