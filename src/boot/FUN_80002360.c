/* FUN_80002360
 * image   boot (boot), base 0x80000480
 * address 0x80002360  body 0x80002360..0x800023d7  size 120 B
 * body sha256 85561712b2b9f56333d84484c50c4e6b6b1c3f95b1c73a64ee43e150cc0bb07e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80002360.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef int code();












void FUN_80002360(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}
