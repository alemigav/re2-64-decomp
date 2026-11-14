/* FUN_8016579c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016579c  body 0x8016579c..0x80165857  size 188 B
 * body sha256 bcde4f9809c2ba13d299601eff53cc4a2058aceaccc564343be21add9c14342e
 * recovered byte-exact (imported: closed by the localtype mechanism pass (14 of 47 -> 47 of 47) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/8016579c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












void FUN_8016579c(int param_1,undefined4 param_2,undefined4 param_3)

{
  unsigned char uVar1;
  uint uVar2;
  
  uVar1 = 4 - *(byte *)(param_1 + 0x26e) / 3;
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
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
