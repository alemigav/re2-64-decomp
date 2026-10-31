/* FUN_80052eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052eec  body 0x80052eec..0x80052f0f  size 39 B
 * sha256  0f8fe35bff60bc7c763f768234c0bcb6ccf77362325ae4b1687b3d817ac602ac
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
char * FUN_80052eec(char *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    uVar1 = uVar1 + 1;
    if (*param_1 == '\0') {
      return param_1;
    }
    param_1 = param_1 + 10;
  } while (uVar1 < 0x20);
  return param_1;
}
