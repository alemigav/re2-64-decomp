/* FUN_8007bf8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bf8c  body 0x8007bf8c..0x8007c007  size 127 B
 * body sha256 26a58f8a641a1d30963d3b4992033307cba8722ff937e6e6608c805c8960b003
 * provider record sha256 f87210b6c4e372b7b4adf613cea24bb8285d1212570c422b7ae111af5016448c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bf8c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b098)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
