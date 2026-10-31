/* FUN_80033604
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033604  body 0x80033604..0x80033647  size 71 B
 * sha256  7dcce7ec2bec1abf32602dcd4035916757e19b5848b313cda7c479bc7f1a4d2e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80033604(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_800df920 >> 7 & 0xff;
  uVar1 = (DAT_800df920 & 0xffff) + uVar2 & 0xff;
  DAT_800df920 = uVar1 | uVar2 << 8;
  return uVar1;
}
