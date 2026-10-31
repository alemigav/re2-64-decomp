/* FUN_8000cde0
 * image   boot (boot), base 0x80000480
 * address 0x8000cde0  body 0x8000cde0..0x8000cdef  size 19 B
 * sha256  5e65314cc0eb11f4c8db021ceb68e9b4cd5a69b29d372e235c148f6ae5959c12
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000cde0(undefined4 param_1)

{
  setCopReg(0,Status,param_1);
  return;
}
