/* FUN_800a2444
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2444  body 0x800a2444..0x800a248f  size 79 B
 * sha256  3a54e0a11b24f86794eff15e932881d12627517be9d19f24a18b05c3d351ce80
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a2444(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)&DAT_8013bc90;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 0x3fe;
    uVar3 = uVar3 + 1;
    FUN_800a0f1c(uVar1);
  } while (uVar3 < 8);
  return;
}
