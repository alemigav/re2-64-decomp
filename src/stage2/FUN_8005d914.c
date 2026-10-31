/* FUN_8005d914
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d914  body 0x8005d914..0x8005d937  size 39 B
 * body sha256 e3dee95f03e20cbedd7e1762895da6dec24aa0611151981365faa8429a38d206
 * provider record sha256 97a760b8ee2a7885f6d879011be8ce098f0fffef9f03c330abb6194b17c6871f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d914(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
