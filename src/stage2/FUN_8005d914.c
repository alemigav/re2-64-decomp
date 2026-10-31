/* FUN_8005d914
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d914  body 0x8005d914..0x8005d937  size 39 B
 * sha256  5b543de60591215eb67333dc131f8c0c88083b0406a3ad89d920571eb15eda95
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d914(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
