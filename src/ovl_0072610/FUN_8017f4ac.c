/* FUN_8017f4ac
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f4ac  body 0x8017f4ac..0x8017f4db  size 48 B
 * body sha256 5a604ea1e05c4f08269cd3b196d5dd2246e37f76eeaa8197f34c2e2e747d29fa
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017f4ac.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_80185780;












undefined4 FUN_8017f4ac(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bbcc();
  if (iVar1 == 0) {
    DAT_80185780 = 1;
  }
  return 1;
}
