/* FUN_8008d160
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d160  body 0x8008d160..0x8008d2e3  size 391 B
 * sha256  8f8bd00ab0c1427fe2db6981f9d6e81ef892abf86f92226c3eb12385cc5aa035
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d160(int param_1)

{
  if (param_1 != 0) {
    if ((DAT_8012bfa4 & 1) == 0) {
      if ((&DAT_800e8eca)[(uint)DAT_8012bfa5 * 4] == '\0') {
        if ((DAT_8012bfa5 & 1) == 0) {
          DAT_8012bfb4 = 0;
        }
        else {
          DAT_8012bfb4 = 4;
        }
      }
      else {
        DAT_8012bfb4 = 2;
      }
    }
    else if ((&DAT_800e8eca)[(uint)DAT_8012bfa5 * 4] == '\0') {
      if ((DAT_8012bfa5 & 1) == 0) {
        DAT_8012bfb4 = 0xfc;
      }
      else {
        DAT_8012bfb4 = 0;
      }
    }
    else {
      DAT_8012bfb4 = 0xfe;
    }
    DAT_8012bfb5 = ((DAT_8012bfa5 >> 1) - (DAT_8012bfa4 >> 1)) * '\x03';
    return;
  }
  if ((DAT_8012bfa4 & 1) == 0) {
    if ((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4] == '\0') {
      if ((DAT_8012bfa5 & 1) == 0) {
        DAT_8012bfb8 = 0;
      }
      else {
        DAT_8012bfb8 = 0xfc;
      }
      goto LAB_8008d2c0;
    }
  }
  else if ((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4] == '\0') {
    if ((DAT_8012bfa5 & 1) == 0) {
      DAT_8012bfb8 = 4;
    }
    else {
      DAT_8012bfb8 = 0;
    }
    goto LAB_8008d2c0;
  }
  if ((DAT_8012bfa5 & 1) == 0) {
    DAT_8012bfb8 = 2;
  }
  else {
    DAT_8012bfb8 = 0xfe;
  }
LAB_8008d2c0:
  DAT_8012bfb9 = ((DAT_8012bfa4 >> 1) - (DAT_8012bfa5 >> 1)) * '\x03';
  return;
}
