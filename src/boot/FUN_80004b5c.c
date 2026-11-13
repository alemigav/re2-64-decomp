/* FUN_80004b5c
 * image   boot (boot), base 0x80000480
 * address 0x80004b5c  body 0x80004b5c..0x80004bab  size 80 B
 * body sha256 23d83892f10b9fe8e4ea5d5d35fdbd54e142d9ecaf1c4f0491d5b9939e8bedd2
 * recovered byte-exact (imported: closed by access type (declsign: char -> unsignedchar) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004b5c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int _DAT_80012878;
extern unsigned int _DAT_80012884;














void FUN_80004b5c(void)

{
  unsigned char cVar1;
  
  cVar1 = func_0x800b43a0(_DAT_80012878);
  if (cVar1 != '\0') {
    func_0x800b431c(_DAT_80012878);
  }
  _DAT_80012884 = 3;
  return;
}
