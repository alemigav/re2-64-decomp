/* func_800b214c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b214c  body 0x800b214c..0x800b21a7  size 95 B
 * body sha256 2e15e63d024c9cb4521bf1cfd5453c8b54b2828e2b52e5ca71181cb632f84031
 * provider record sha256 40bb24b4f28c1abbdee49469055eb9fa4ab06d8e05ecf0c08817afb96b4f06fe
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800b214c(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  int in_v0;
  
  if (in_v0 != 0) {
    FUN_800a5678();
    FUN_800a7e30(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
