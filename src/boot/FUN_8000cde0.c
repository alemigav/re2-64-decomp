/* FUN_8000cde0
 * image   boot (boot), base 0x80000480
 * address 0x8000cde0  body 0x8000cde0..0x8000cdef  size 19 B
 * body sha256 59cc9514a446102126f66c3f082c35bd6e025ec79b48c8b39cf3f9e10e172bc4
 * provider record sha256 e08164c242bcb153c0b2a70e4b2906330269f9dc7eee47c660dbc110ee77a3a3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000cde0(undefined4 param_1)

{
  setCopReg(0,Status,param_1);
  return;
}
