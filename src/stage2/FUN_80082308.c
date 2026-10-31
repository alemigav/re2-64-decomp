/* FUN_80082308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082308  body 0x80082308..0x80082387  size 131 B
 * sha256  391cdf0a269e323d2d4279d40f688fec1050323bbdd133f05464139cd2374ccf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80082308(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_1 - (uint)*param_2;
  if (uVar2 == 0) {
    if (*param_1 != 0) {
      do {
        bVar1 = *param_2;
        if (bVar1 == 0) break;
        param_2 = param_2 + 1;
        uVar2 = (uint)*param_1 - (uint)bVar1;
        param_1 = param_1 + 1;
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar2 = 0;
      } while (*param_1 != 0);
    }
    if (((uVar2 == 0) && (uVar2 = (uint)*param_1, uVar2 == 0)) &&
       (uVar2 = -(uint)*param_2, *param_2 == 0)) {
      return 0;
    }
  }
  return uVar2;
}
