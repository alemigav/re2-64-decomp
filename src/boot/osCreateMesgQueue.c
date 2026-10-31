/* osCreateMesgQueue
 * image   boot (boot), base 0x80000480
 * address 0x80006d30  body 0x80006d30..0x80006d53  size 39 B
 * body sha256 2b745931095f0111344f87e584219692d649e54d62ebe5383bcc4722abefcb13
 * provider record sha256 43643742ec38e26a63e31051d82937a2c20b3095cbb466948898d3abdd3d84c3
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
