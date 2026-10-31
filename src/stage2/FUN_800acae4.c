/* FUN_800acae4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acae4  body 0x800acae4..0x800acbb7  size 215 B
 * sha256  4e6deab108446ff00e679c8091da7b127fa8b3250091a34f262ee10e6d9cad74
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800acae4(int param_1,byte param_2,short param_3)

{
  byte bVar1;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x3fff < param_3) {
    param_3 = 0x3fff;
  }
  bVar1 = param_2;
  switch(param_2) {
  case 0x80:
    bVar1 = 0x80;
    break;
  case 0x81:
    bVar1 = 0x82;
    break;
  case 0x82:
    bVar1 = 0xa0;
    break;
  case 0x83:
    bVar1 = 0xa1;
    break;
  case 0x84:
    bVar1 = 0x83;
    break;
  case 0x85:
    bVar1 = 0x84;
  }
  if (((0xa1 < bVar1) || (bVar1 < 0xa0)) && (*(char *)(param_1 + 0x4a) != -1)) {
    FUN_800ab7e0(param_2,*(char *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b),param_3);
  }
  return;
}
