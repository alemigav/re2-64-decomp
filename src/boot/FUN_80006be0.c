/* FUN_80006be0
 * image   boot (boot), base 0x80000480
 * address 0x80006be0  body 0x80006be0..0x80006d2f  size 339 B
 * sha256  d4da28aba632a3c54372958bed851c45bd656f20da9c52bf32dd9bbe6a029c65
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80006d0c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_80006be0(float param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  if (((int)param_1 >> 0x16 & 0x1ffU) < 0x136) {
    if (param_1 <= 0.0) {
      param_1 = -param_1;
    }
    dVar2 = (double)param_1 * _DAT_80011ae8 + _DAT_80011b08;
    if (0.0 <= dVar2) {
      dVar2 = dVar2 + _DAT_80011b08;
    }
    else {
      dVar2 = dVar2 - _DAT_80011b08;
    }
    dVar3 = (double)(int)dVar2 - _DAT_80011b10;
    dVar3 = ((double)param_1 - dVar3 * _DAT_80011af0) - dVar3 * _DAT_80011af8;
    dVar4 = dVar3 * dVar3;
    dVar3 = dVar3 + dVar3 * dVar4 *
                    (((_DAT_80011ae0 * dVar4 + _DAT_80011ad8) * dVar4 + _DAT_80011ad0) * dVar4 +
                    _DAT_80011ac8);
    if (((int)dVar2 & 1U) == 0) {
      fVar1 = (float)dVar3;
    }
    else {
      fVar1 = -(float)dVar3;
    }
  }
  else {
    fVar1 = _DAT_80011b00;
  }
  return fVar1;
}
