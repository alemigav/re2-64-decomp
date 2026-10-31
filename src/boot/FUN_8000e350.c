/* FUN_8000e350
 * image   boot (boot), base 0x80000480
 * address 0x8000e350  body 0x8000e350..0x8000e3ab  size 95 B
 * body sha256 aa79d63fa3b7cbdf62ca66c809174a63c760726dc0166d203c4a8d60cad4add6
 * provider record sha256 a391df5614a8327ecd9391fab93684d9f4dc8c3a52286c8010130b618545aecb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e350(char param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar1 = FUN_800072e0();
  if (param_1 == '\0') {
    uVar2 = *_DAT_800129d4 & 0xffdf;
  }
  else {
    uVar2 = *_DAT_800129d4 | 0x20;
  }
  *_DAT_800129d4 = uVar2;
  FUN_80007300(uVar1);
  return;
}
