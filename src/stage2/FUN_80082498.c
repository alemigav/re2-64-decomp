/* FUN_80082498
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082498  body 0x80082498..0x800824af  size 27 B
 * body sha256 a7f37e11f2938a40c28f64632727b99e5b17672f8f8630480dabe5c261e5b5a7
 * provider record sha256 8a2fa6936f10fe0c94b88f3a40e7b61c4ece3b31bffca9c1c3fefb642ab9b4ca
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082498(undefined4 *param_1,int param_2)

{
  do {
    *param_1 = 0;
    param_2 = param_2 + -1;
    param_1 = param_1 + 1;
  } while (param_2 != 0);
  return;
}
