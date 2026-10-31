/* FUN_80162568
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80162568  body 0x80162568..0x8016259b  size 55 B
 * sha256  5684059387b5a6cd3b403741910f8bcf1e6bf30a98596601bbc53d7a4f734948
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162568(int param_1)

{
  (**(code **)(&DAT_80162b1c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
