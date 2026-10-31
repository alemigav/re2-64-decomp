/* FUN_8002fcc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fcc0  body 0x8002fcc0..0x8002fccf  size 19 B
 * sha256  96abdc815e11aae0bcc6ff2e53f244dc40859b68ee7fc23eaeff496c6b98ac25
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002fcc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  return *(int *)(*(int *)(param_1 + 4) + 0x2c) - param_4;
}
