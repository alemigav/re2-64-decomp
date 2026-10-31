/* FUN_80171484
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171484  body 0x80171484..0x801714df  size 95 B
 * sha256  34c3d668e6e3555fce72f22574577c4e67dc2842db37e07eaa05f6518409ac01
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80171484(int param_1)

{
  bool bVar1;
  
  bVar1 = DAT_800c56f4 == '\0';
  while (param_1 = param_1 + -1, param_1 != 0) {
    DAT_800c56f4 = bVar1;
    func_0x8004cd88(1);
  }
  return;
}
