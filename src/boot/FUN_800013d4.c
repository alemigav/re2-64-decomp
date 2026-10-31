/* FUN_800013d4
 * image   boot (boot), base 0x80000480
 * address 0x800013d4  body 0x800013d4..0x800014ab  size 219 B
 * sha256  1cec225b74eadcd43fc66096ea4b51535c1a167a68ee19376520a5083d9d6962
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800013d4(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = _DAT_800138a4;
  if ((param_1 & 3) != 0) {
    param_1 = param_1 + 7 & 0xfffffff8;
  }
  uVar4 = 0;
  if (_DAT_80013eb4 != 0) {
    uVar5 = _DAT_80013eb4 - 1;
    piVar2 = (int *)&DAT_800138b0;
    do {
      if ((piVar2[2] == 0) && (param_1 <= (uint)piVar2[1])) {
        piVar2[2] = 1;
        if (uVar4 == uVar5) {
          piVar2[1] = param_1;
        }
        return *piVar2;
      }
      uVar4 = uVar4 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar4 < _DAT_80013eb4);
  }
  iVar3 = _DAT_80013eb4 * 0xc;
  *(int *)(&DAT_800138b0 + iVar3) = _DAT_800138a4;
  _DAT_800138a4 = _DAT_800138a4 + param_1;
  *(uint *)(&DAT_800138b4 + iVar3) = param_1;
  *(undefined4 *)(&DAT_800138b8 + iVar3) = 1;
  _DAT_80013eb4 = _DAT_80013eb4 + 1;
  _DAT_80013eb0 = _DAT_800138a4;
  return iVar1;
}
