/* FUN_80062b80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062b80  body 0x80062b80..0x80062c6f  size 243 B
 * body sha256 bee2a237fecf82271bb36d52d87e427c2401a3c6301f4ab1779855a434881dfc
 * provider record sha256 8112e527b1e0ec9ed463dba06d3d6a00840d16da020d6aff53c5365983eec7cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80062b80(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 < 0x20000) {
    param_1 = param_1 >> 6 & 0x7ff;
  }
  else {
    iVar1 = 1;
    if (param_1 < 0x30000) {
      param_1 = param_1 >> 5 & 0x7ff;
    }
    else {
      iVar1 = 2;
      if (param_1 < 0x38000) {
        param_1 = param_1 >> 4 & 0x7ff;
      }
      else {
        iVar1 = 3;
        if (param_1 < 0x3c000) {
          param_1 = param_1 >> 3 & 0x7ff;
        }
        else {
          iVar1 = 4;
          if (param_1 < 0x3e000) {
            param_1 = param_1 >> 2 & 0x7ff;
          }
          else {
            iVar1 = 5;
            if (param_1 < 0x3f000) {
              param_1 = param_1 >> 1 & 0x7ff;
            }
            else {
              iVar1 = 6;
              if (0x3f7ff < param_1) {
                iVar1 = 7;
              }
              param_1 = param_1 & 0x7ff;
            }
          }
        }
      }
    }
  }
  return param_1 << 2 | iVar1 << 0xd;
}
