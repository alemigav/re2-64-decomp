/* FUN_800787dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800787dc  body 0x800787dc..0x80078823  size 75 B
 * sha256  af4bcc08cd2b523af916f5cd0ab8d3f37946d8a5705d7ece6d655ea0031a6cfd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800787dc(uint param_1,byte param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((byte)(&DAT_80119efc)[(param_1 & 0xff) * 2] <= (param_2 & 7)) &&
      (uVar1 = 0, (&DAT_80119efc)[(param_1 & 0xff) * 2] == (param_2 & 7))) &&
     (uVar1 = 1, (param_2 & 8) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}
