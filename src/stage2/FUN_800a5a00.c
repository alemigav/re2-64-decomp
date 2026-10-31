/* FUN_800a5a00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a00  body 0x800a5a00..0x800a5a5f  size 99 B
 * body sha256 2f37c87848ccda700571e6d57a62d7550773fbefac8f36cfce96d2dbe59e11fb
 * provider record sha256 8b7138fc5e4581d9a52575f4b47f578dccfe4259d10bb916d94d7a7baa7ffb99
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5a00(int param_1,ushort param_2)

{
  if (param_2 < 0x2001) {
    *(ushort *)(param_1 * 0x68 + _DAT_80143f0c + 4) = param_2;
    return;
  }
  *(undefined2 *)(param_1 * 0x68 + _DAT_80143f0c + 4) = 0x2000;
  return;
}
