/* FUN_800879d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800879d0  body 0x800879d0..0x80087a27  size 91 B
 * sha256  be694704c27dee55740c784361598eaa27a91b5d0affdeecbcbad7e4adb463c7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800879d0(undefined4 *param_1)

{
  func_0x800066f0(0x8013a2f0);
  osRecvMesg(0x8013a2f0,0,1);
  osSendMesg(param_1[1],*param_1,0);
  return;
}
