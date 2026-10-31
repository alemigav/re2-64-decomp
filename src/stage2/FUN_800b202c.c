/* FUN_800b202c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b202c  body 0x800b202c..0x800b2097  size 111 B
 * sha256  641be125dae1954e70cc8cd8e1de51ac57731519452a5a141e09f6ddcf7e9976
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b202c(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a7b64(param_1,param_2,param_3,0,0);
    FUN_800a56c0();
  }
  return;
}
