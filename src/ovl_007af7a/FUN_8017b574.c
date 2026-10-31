/* FUN_8017b574
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b574  body 0x8017b574..0x8017b5cb  size 91 B
 * sha256  70356c4ab8de129c10e53aeb61954d24c980f592c382688ecf4c1f1c0be62b1f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b574(void)

{
  int iVar1;
  
  iVar1 = func_0x8002767c(0);
  if (iVar1 != 0) {
    func_0x800274f8(0x200,0,7,1);
    DAT_8017e5c9 = 1;
    DAT_8017e5bf = DAT_8017e5bf & 0xf7;
    func_0x8006c070();
  }
  return;
}
