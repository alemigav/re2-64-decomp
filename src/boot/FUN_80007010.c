/* FUN_80007010
 * image   boot (boot), base 0x80000480
 * address 0x80007010  body 0x80007010..0x80007027  size 27 B
 * sha256  9e301ed9e410fff1fc3acdfd0e53303d4c47691767a85b406c15a27c8ebf1c04
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80007010(int param_1)

{
  if (param_1 == 0) {
    param_1 = _DAT_80012950;
  }
  return *(undefined4 *)(param_1 + 4);
}
