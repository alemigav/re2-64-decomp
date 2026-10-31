/* FUN_80165c68
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165c68  body 0x80165c68..0x80165c73  size 15 B
 * sha256  33dc646514b2e0c77439cb73afde889886ec9a0c66bf44c6c071eca9636578e6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c68(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = param_2;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}
