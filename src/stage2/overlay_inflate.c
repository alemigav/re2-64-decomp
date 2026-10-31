/* overlay_inflate
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cbf4  body 0x8004cbf4..0x8004cc5b  size 107 B
 * sha256  f5df2493e9799017c4f8dfba6d18212aefb3b852af00aa31ff708d1cd9298ef9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 overlay_inflate(undefined4 *param_1)

{
  undefined1 auStack_60 [20];
  undefined4 local_4c;
  
  if (param_1[1] == 0) {
    local_4c = 0;
  }
  else {
    inflate_init(auStack_60,DAT_8010b6fc);
    inflate(auStack_60,*param_1,param_1[2],param_1[1]);
    inflate_free(auStack_60,2);
  }
  return local_4c;
}
