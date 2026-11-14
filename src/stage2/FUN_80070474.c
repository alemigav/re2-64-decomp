/* FUN_80070474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070474  body 0x80070474..0x800704df  size 108 B
 * body sha256 31a4844a848e75e22bcfdc5c74317e07a993aacde8878ef68d30204c192c3806
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (25 of 27 -> 27 of 27) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80070474.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
extern short DAT_800e8c78;












undefined4 FUN_80070474(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800704e0(*(undefined4 *)(param_1 + 0x154),
                       *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2));
  FUN_8006e838(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),uVar1,
               (int)(short)(&DAT_800e8c78)[*(byte *)(*(int *)(param_1 + 0x1c) + 3)]);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
