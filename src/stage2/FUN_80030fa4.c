/* FUN_80030fa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030fa4  body 0x80030fa4..0x80030fc3  size 35 B
 * body sha256 5c476a698422b61f511fe5ab6277461d2ce549ab233f3db179fc2f0c0dac97d6
 * provider record sha256 79ea536980337ba34bec86dff3b2483f332d8794048eb0b9cb8fa042a6addcef
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
