/* FUN_80082474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082474  body 0x80082474..0x80082497  size 39 B
 * body sha256 b3343858898404f8bed4ff1fee99d159a88c13e523700ce83c266885a3dc18a7
 * provider record sha256 f6afc61c1b1b562a539c53508b1a1df05f39fbe4218d723119c15b9197c31264
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082474(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  do {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_1 < puVar1);
  return;
}
