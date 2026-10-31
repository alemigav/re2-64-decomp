/* func_80161cf0
 * image   ovl_00b6040 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161d6b  size 127 B
 * sha256  8df94e36509ec490454711a2981aee98220bb733c50998e313eb1afb7319594d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  if (((_DAT_800e1110 & 0x20000000) == 0) &&
     ((*(code *)(&PTR_FUN_80162050)[*(byte *)(in_a0 + 4)])(), *(short *)(in_a0 + 0x270) == 1)) {
    *(undefined4 *)(in_a0 + 4) = 0x3000000;
    *(undefined2 *)(in_a0 + 0x270) = 0;
  }
  return;
}
