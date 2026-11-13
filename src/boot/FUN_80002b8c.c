/* FUN_80002b8c
 * image   boot (boot), base 0x80000480
 * address 0x80002b8c  body 0x80002b8c..0x80002bb3  size 40 B
 * body sha256 505a75965932de6f6fe093a98c3c6c41360d18b85ce39e10538146ad124dc937
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80002b8c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef void code();












void FUN_80002b8c(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}
