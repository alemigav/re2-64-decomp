/* FUN_80085300
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80085300  body 0x80085300..0x80085397  size 155 B
 * sha256  11174796b576dad50636ea49eaf438e3a80a88be7198e9bd3522b20e891ce50f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80085300(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x7f;
  if ((&DAT_8012487c)[uVar2 * 4] == param_1) {
    (&DAT_8012486c)[uVar2 >> 5] =
         (&DAT_8012486c)[uVar2 >> 5] & ~(1 << ((&DAT_8012487c)[uVar2 * 4] & 0x1f));
    uVar1 = func_0x800072e0();
    (&DAT_80124880)[uVar2 * 4] = DAT_8012485c;
    DAT_80124868 = DAT_80124868 + -1;
    DAT_8012485c = uVar2;
    func_0x80007300(uVar1);
  }
  return;
}
