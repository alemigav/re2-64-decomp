/* FUN_80040cf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040cf4  body 0x80040cf4..0x80040d2b  size 59 B
 * body sha256 f88428edf48ef329fe0cf0fd0648124581cbeb090b5ed80cf2c479e4dd02d03c
 * provider record sha256 4b505aaa8e0793cad9e612ea8289974cc2d62cb6fc7a06dfc514d59b1d6ade69
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80040cf4(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [32];
  
  FUN_8004226c(param_1,param_2,auStack_28);
  FUN_800424bc(auStack_28,param_2);
  return param_2;
}
