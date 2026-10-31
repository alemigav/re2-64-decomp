/* FUN_80007300
 * image   boot (boot), base 0x80000480
 * address 0x80007300  body 0x80007300..0x8000731b  size 31 B
 * body sha256 bdbe9d3712c21746ed85dea4c9fee0abec77890ded6f995861c0888442a6730e
 * provider record sha256 907d2ba2e37ef59a1ac9a58cfd50c9192282c82907b5d4e88f75c74a738ed937
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80007300(uint param_1)

{
  setCopReg(0,Status,Status | param_1);
  return;
}
