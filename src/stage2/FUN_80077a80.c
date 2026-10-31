/* FUN_80077a80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077a80  body 0x80077a80..0x80077adb  size 95 B
 * body sha256 d03e4825f792e9b633bb402e6164dda76cf874e98758c4504b0cdcd21a20306c
 * provider record sha256 ea18bcd8425a57d89ab1ca5c4481bf022aa8e75b0db8876defdac13448420a64
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077a80(uint param_1)

{
  byte bVar1;
  undefined2 uVar2;
  
  bVar1 = (&DAT_80117117)[param_1 >> 0x18];
  uVar2 = FUN_800844cc((int)(short)param_1);
  *(undefined2 *)(&UNK_800e8b5c + (param_1 >> 0xf & 0x1fe) + (uint)bVar1 * 2) = uVar2;
  return;
}
