/* inflate_free
 * image   boot (boot), base 0x80000480
 * address 0x80004594  body 0x80004594..0x800045db  size 75 B
 * sha256  3069931ee6212c5fafe3bd07fa0a121b95b780c6b458205dd51a59ca31011197
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void inflate_free(int param_1,uint param_2)

{
  FUN_800014ac(*(undefined4 *)(param_1 + 0x4c));
  if ((param_2 & 1) != 0) {
    func_0x8008b0a4(param_1);
  }
  return;
}
