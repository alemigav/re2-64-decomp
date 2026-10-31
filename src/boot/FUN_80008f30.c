/* FUN_80008f30
 * image   boot (boot), base 0x80000480
 * address 0x80008f30  body 0x80008f30..0x80008f77  size 75 B
 * body sha256 8800ce8aebbc5c56f622ea0ab9eeab9994f78e4e1421ea9ed8efbcbe65448531
 * provider record sha256 27e1d35da191cd3cbf0ed630f9b188424732c1b6e91440e650040eee75475295
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80008f30(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = 0xf;
  do {
    uVar2 = (uVar1 & 0x7f) << 1;
    if ((param_1 & 0x400) != 0) {
      uVar2 = uVar2 | 1;
    }
    param_1 = param_1 << 1;
    uVar1 = uVar2 ^ -(uint)((uVar1 & 0x10) != 0) & 0x15;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  return uVar1 & 0x1f;
}
