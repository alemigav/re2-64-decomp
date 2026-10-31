/* FUN_80082200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082200  body 0x80082200..0x80082223  size 39 B
 * sha256  2c384080c4294eaeec901a087be784214f81fdbe97ca791e537fcf7e62245cde
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082200(undefined1 *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + -1;
  if (param_3 != 0) {
    do {
      *param_1 = param_2;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}
