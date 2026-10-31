/* FUN_80030fa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030fa4  body 0x80030fa4..0x80030fc3  size 35 B
 * sha256  ab77484c55f7f3495ad571797f2aa242645fa74e27f88a44c7ebcaf0b56609e1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030fa4(undefined1 *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}
