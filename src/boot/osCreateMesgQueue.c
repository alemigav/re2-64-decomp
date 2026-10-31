/* osCreateMesgQueue
 * image   boot (boot), base 0x80000480
 * address 0x80006d30  body 0x80006d30..0x80006d53  size 39 B
 * body sha256 2b745931095f0111344f87e584219692d649e54d62ebe5383bcc4722abefcb13
 * provider record sha256 1e1047541ce89d9acdb098d82a7bde899149a0c7fa275750763c9b8f43a0475f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void osCreateMesgQueue(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0x80012940;
  param_1[1] = 0x80012940;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_3;
  param_1[5] = param_2;
  return;
}
