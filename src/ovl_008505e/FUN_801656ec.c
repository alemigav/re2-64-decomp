/* FUN_801656ec
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801656ec  body 0x801656ec..0x8016579b  size 176 B
 * body sha256 272021f923107f612ceea17025930e8b508f7398f1baad64e1cf68ba3f91f7dd
 * recovered byte-exact (imported: closed by the localtype mechanism pass (14 of 44 -> 44 of 44) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801656ec.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












void FUN_801656ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  unsigned char uVar1;
  uint uVar2;
  
  uVar1 = 2 - *(byte *)(param_1 + 0x26e) / 3;
  *(char *)(param_1 + 699) = (char)uVar1;
  uVar2 = 0;
  if ((uVar1 & 0xff) != 0) {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = func_0x80033604();
      FUN_80166980(param_1,uVar1 & 0xf,8);
    } while (uVar2 < *(byte *)(param_1 + 699));
  }
  *(undefined1 *)(param_1 + 5) = 1;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
