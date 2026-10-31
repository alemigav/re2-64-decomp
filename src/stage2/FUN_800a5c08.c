/* FUN_800a5c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c08  body 0x800a5c08..0x800a5c33  size 47 B
 * body sha256 57816c2c45cf67df22a593f36e2d064b92f7c2eb5405d4acc62701ccc67324d1
 * provider record sha256 98aaf108a08d874188a5274ed904323b47fa8c6ba5cf1a00f0789d100a68456d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a5c08(int param_1)

{
  return *(undefined4 *)(param_1 * 0x68 + _DAT_80143f0c + 0x14);
}
