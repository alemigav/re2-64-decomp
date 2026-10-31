/* FUN_80052eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052eec  body 0x80052eec..0x80052f0f  size 39 B
 * body sha256 5e0099c5a10076cd663b3260c72a44cd513032ecc5bcafc5fb7e901c7ace25f5
 * provider record sha256 d9c575965f5ce81208b2b75b546c48555e1a7d5686f705bbdf82fe10dee666d9
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
