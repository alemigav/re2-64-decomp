/* FUN_800787dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800787dc  body 0x800787dc..0x80078823  size 75 B
 * body sha256 4066e26704ee1466415bbb73cc6820590e6fb789d02eb306e54f66c6ed82a02f
 * provider record sha256 17bd1b02d616c08804caff3d67f091b52d90be93683de8e698afff86bab93ceb
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
