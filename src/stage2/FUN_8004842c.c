/* FUN_8004842c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004842c  body 0x8004842c..0x800484db  size 179 B
 * sha256  c8fdfb6bffb878b79a3366ce494d17e9147b7e5a137a6b32b9bead88e75bfbd6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_8004842c(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (param_1 == 0.0) {
    fVar1 = 0.0;
    if (param_2 <= 0.0) {
      fVar1 = 3.1415927;
    }
  }
  else {
    fVar1 = (float)FUN_800482e0(param_1 / param_2);
    if (param_2 < fVar2) {
      if (param_1 < fVar2) {
        fVar1 = fVar1 - 3.1415927;
      }
      else {
        fVar1 = fVar1 + 3.1415927;
      }
    }
  }
  return fVar1;
}
