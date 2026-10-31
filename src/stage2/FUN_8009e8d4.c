/* FUN_8009e8d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e8d4  body 0x8009e8d4..0x8009e93b  size 107 B
 * body sha256 b2a802f207f77c7322c4c8b84e00b89b0e320a0e0a0027da469def02184fc120
 * provider record sha256 4f805e3324330713cab9b7e44bf6e3044f41d6c95ef38d767b328370d2a47b17
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e8d4(undefined1 param_1,char param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = DAT_80132748;
  do {
    if ((DAT_80132740 >> (uVar2 & 0x1f) & 1) == 0) {
      if (param_2 != '\0') {
        *puVar1 = 0;
      }
    }
    else {
      *puVar1 = param_1;
    }
    if ((puVar1[1] & 0x10) != 0) {
      *puVar1 = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0xc;
  } while (uVar2 < (uint)(int)DAT_80132738);
  return;
}
