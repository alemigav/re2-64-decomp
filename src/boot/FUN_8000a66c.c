/* FUN_8000a66c
 * image   boot (boot), base 0x80000480
 * address 0x8000a66c  body 0x8000a66c..0x8000a6b7  size 76 B
 * body sha256 3fb929a8b8c7f9b0c853deda27f904cd20d2ec9eaecdafb9cc101cfbed081fe8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000a66c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_8000a66c(int param_1)

{
  undefined1 *puVar1;
  undefined1 local_28 [32];
  
  puVar1 = local_28;
  do {
    *puVar1 = *(undefined1 *)(param_1 + 0x65);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < (int)(local_28 + 0x20));
  FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0x400,local_28,0);
  return;
}
