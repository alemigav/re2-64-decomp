/* FUN_80071618
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071618  body 0x80071618..0x8007166f  size 88 B
 * body sha256 04ecd9b23f8ca9656a8c872b68060e6ec042ec5ebbbdf3de9a20a635fa27c5b6
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80071618.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80071618(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800717a0((int)*(char *)(*(int *)(param_1 + 0x1c) + 3),
                       (int)*(char *)(*(int *)(param_1 + 0x1c) + 4));
  FUN_80038e98(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
               *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2),uVar1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 5;
  return 1;
}
