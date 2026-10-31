/* FUN_800478ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478ac  body 0x800478ac..0x800478b7  size 15 B
 * sha256  8811f442c6dce8466197c72f9ee2c2f5fbd7fcd8f2d414e566262729cc6eb42f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478ac(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  return;
}
