/* FUN_800a5b14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5b14  body 0x800a5b14..0x800a5b7b  size 107 B
 * sha256  b5648c755fa9e02a6a0f6d6744778ebf719a805807549faa5b1c9105b5c7cea8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5b14(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 * 0x68 + _DAT_80143f0c);
  if (*pcVar1 != '\0') {
    pcVar1[0x28] = '\0';
    pcVar1[0x29] = '\x14';
    if (pcVar1[1] != '\0') {
      pcVar1[1] = '\0';
      return;
    }
    pcVar1[0x5c] = '\x03';
    pcVar1[0x54] = '\0';
    pcVar1[0x55] = '\0';
    pcVar1[0x56] = '\0';
    pcVar1[0x57] = '\0';
    pcVar1[0x50] = '\0';
    pcVar1[0x51] = '\0';
    pcVar1[0x52] = '\0';
    pcVar1[0x53] = '\0';
    *(undefined4 *)(pcVar1 + 0x58) = *(undefined4 *)(pcVar1 + 0x4c);
    *(undefined2 *)(pcVar1 + 0x48) = *(undefined2 *)(pcVar1 + 0x28);
  }
  return;
}
