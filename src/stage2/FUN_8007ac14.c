/* FUN_8007ac14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ac14  body 0x8007ac14..0x8007acbf  size 175 B
 * body sha256 628c54339f418aa6ec41081c0c51b9b13d744510c5cec94b7a3e61ff2018db90
 * provider record sha256 e5dd9a26e8919c72953f9e238446d779a157728359d98e536765381812ad5dbf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ac14(int param_1)

{
  if ((DAT_800e9012 & 0xc) != 0) {
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
  }
  return;
}
