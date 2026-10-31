/* FUN_8004cd88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd88  body 0x8004cd88..0x8004cdd3  size 79 B
 * sha256  779c4b86a55df40fc98ff078ce048d5c76aa7b2014016a3f66b8ecc35b0d055b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cd88(undefined2 param_1)

{
  DAT_8010b6b8[1] = param_1;
  *DAT_8010b6b8 = 1;
  func_0x80007450(0x80139b30,0,0);
  func_0x8000dcb0(0);
  return;
}
