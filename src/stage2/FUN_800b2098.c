/* FUN_800b2098
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2098  body 0x800b2098..0x800b2137  size 163 B
 * body sha256 6767b3a40089f458669ac736dbb1bc3ad5dddcf2b434da322892e2daaaae4e2a
 * provider record sha256 50f3e27d4af5795eb58bff97ef9e1c0a617e78ff6608822ca882092eb4cdb6c7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b2098(undefined1 param_1,undefined2 param_2,char param_3,char param_4)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if (param_3 != '\0') {
      FUN_800a7b64(param_1,param_2,0x15,0,0);
    }
    if (param_4 != '\0') {
      FUN_800a7b64(param_1,param_2,0x16,0,0);
    }
    FUN_800a56c0();
  }
  return;
}
