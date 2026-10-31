/* FUN_800a5c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c08  body 0x800a5c08..0x800a5c33  size 47 B
 * sha256  3855b21e9fa030e5d29154fab8823978cc1c5ed163d2f32aceb4fda214b7e786
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a5c08(int param_1)

{
  return *(undefined4 *)(param_1 * 0x68 + _DAT_80143f0c + 0x14);
}
