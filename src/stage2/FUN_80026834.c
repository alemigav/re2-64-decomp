/* FUN_80026834
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026834  body 0x80026834..0x8002687b  size 72 B
 * body sha256 52fcb05defb7c3b6a4c83346aae7cf0e81a8afeb4bb72ac2af38ceff77924474
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (9 of 18 -> 18 of 18) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80026834.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern unsigned char DAT_80112968;












void FUN_80026834(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  (&DAT_80112968)[param_1] = param_2;
  func_0x80007300(uVar1);
  return;
}
