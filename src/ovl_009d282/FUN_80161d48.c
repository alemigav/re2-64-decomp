/* FUN_80161d48
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161d48  body 0x80161d48..0x80161daf  size 107 B
 * sha256  476090d590ff70d8c8b8d546f2fc6931e41f9546bf01bfdba8c9eefd66631310
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161d48(uint *param_1)

{
  param_1[1] = 0x1000000;
  func_0x80089d54();
  *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
  *param_1 = *param_1 | 0x44a;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  FUN_80161e1c(param_1);
  return;
}
