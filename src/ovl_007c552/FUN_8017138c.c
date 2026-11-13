/* FUN_8017138c
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8017138c  body 0x8017138c..0x801713af  size 36 B
 * body sha256 f9d7f888a1ba480d943c39ca861f67b00f41dfdf59e315816cdf05d47f0f78d4
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007c552/8017138c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_8017138c(undefined4 *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined2 *)*param_1;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x140);
  *param_1 = puVar1;
  return;
}
