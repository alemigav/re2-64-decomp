/* FUN_80004c34
 * image   boot (boot), base 0x80000480
 * address 0x80004c34  body 0x80004c34..0x80004c6b  size 56 B
 * body sha256 1adb15d3bb86378ff5dd3fe3b15a9140e1e273c2e8ae15d0261b489c5f664089
 * recovered byte-exact (imported: closed by access type (declsign: char -> unsignedchar) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004c34.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int _DAT_80012878;
extern unsigned int _DAT_80012884;














void FUN_80004c34(void)

{
  unsigned char cVar1;
  
  cVar1 = func_0x800b43a0(_DAT_80012878);
  if (cVar1 == '\0') {
    _DAT_80012884 = 3;
  }
  return;
}
