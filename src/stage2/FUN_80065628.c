/* FUN_80065628
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065628  body 0x80065628..0x8006568b  size 103 B
 * sha256  7c1364a5934e34410d61afd93f0b46b522b65e7abbdb8ee4259d8299d2535a7d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80065628(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)**(ushort **)(DAT_800df92c + 0x38);
  uVar1 = 0xff;
  if (uVar2 != 0) {
    uVar1 = FUN_80033604();
    uVar1 = (uVar1 & 0xff) % uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
  }
  return uVar1;
}
