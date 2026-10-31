/* FUN_800a5890
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5890  body 0x800a5890..0x800a58bb  size 47 B
 * sha256  cc73e9693364c22f883379e73b4b3f82bf4fdc98409467a6eea9b2e2813f36d1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_800a5890(int param_1)

{
  return *(char *)(param_1 * 0x68 + _DAT_80143f0c) != '\0';
}
