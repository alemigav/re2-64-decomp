/* FUN_800a1fc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1fc8  body 0x800a1fc8..0x800a200b  size 71 B
 * body sha256 de8401e3ed6a16682b94d8793ac1e3694a50a7782c06bcdb0dd736bde287b50d
 * provider record sha256 0752bf68902f4179c8895449970881f1e9e5affdecbe9db35f931c49cb95a543
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1fc8(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a1234(param_1);
    FUN_800a56c0();
  }
  return;
}
