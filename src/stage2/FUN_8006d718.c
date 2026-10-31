/* FUN_8006d718
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d718  body 0x8006d718..0x8006d7a3  size 143 B
 * sha256  344872300bc393cfcc7aa420b2f629dcb64f6f5beffcf66e3a479a5e58ebdbf7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d718(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_8010bf7e;
  uVar2 = 0;
  if (uVar3 != 0) {
    pbVar1 = &DAT_8010bc34;
    do {
      if ((*pbVar1 & 0x80) == 0) {
        if ((*pbVar1 & 0x40) != 0) {
          FUN_8004fc3c(uVar2,pbVar1);
        }
      }
      else {
        FUN_8004fc34(uVar2,pbVar1);
      }
      pbVar1 = pbVar1 + 0x1c;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return;
}
