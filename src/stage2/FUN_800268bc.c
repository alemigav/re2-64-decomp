/* FUN_800268bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800268bc  body 0x800268bc..0x8002690f  size 87 B
 * body sha256 9eaeba4f128647b863515ecb46a82fabb9bc0a4bfb9d93a35568288b81ef98b8
 * provider record sha256 009862ba4a4d94a0f1d51db674a8a3546f43afcaac3e51a7c62b1f0e8bd14313
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800268bc(void)

{
  undefined4 uVar1;
  
  if (DAT_801127e0 == 0) {
    if (DAT_800c56f4 == '\0') {
      uVar1 = DAT_8010b6e4;
    }
    else {
      uVar1 = DAT_8010b6e0;
    }
    FUN_8006bf48(uVar1);
  }
  return;
}
