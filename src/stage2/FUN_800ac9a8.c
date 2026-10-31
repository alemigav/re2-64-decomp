/* FUN_800ac9a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac9a8  body 0x800ac9a8..0x800aca07  size 99 B
 * sha256  5a05d6e81687c0c6a0f4f762ea3ccf95ff928f4938b676de2b292a94b26f12d9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac9a8(undefined1 param_1)

{
  switch(param_1) {
  case 0x80:
    param_1 = 0x80;
    break;
  case 0x81:
    param_1 = 0x82;
    break;
  case 0x82:
    param_1 = 0xa0;
    break;
  case 0x83:
    param_1 = 0xa1;
    break;
  case 0x84:
    param_1 = 0x83;
    break;
  case 0x85:
    param_1 = 0x84;
  }
  return param_1;
}
