/* func_8016e880
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016e880  body 0x8016e880..0x8016e8cf  size 83 B
 * sha256  049626ae7055604926d31aa0ce963dc7a353883663b62be3aef79cb4238a2b9f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void processEntry entry(void)

{
  FUN_8016e8d0();
  do {
    (*(code *)(&PTR_FUN_80171860)[DAT_80171dd9])();
    FUN_8016fb54();
    func_0x8004cd88(1);
  } while( true );
}
