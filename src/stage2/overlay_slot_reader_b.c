/* overlay_slot_reader_b
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd08  body 0x8004cd08..0x8004cd53  size 79 B
 * sha256  535ec20ed9706d835439bc7f93923cf772c9cfad1ec0d46105cb7554a9e81c9a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void overlay_slot_reader_b(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = cart_record((&DAT_8010b2e0)[param_1 * 8]);
  overlay_inflate(uVar1);
  FUN_8004ce40(*(undefined4 *)(&DAT_8010b2e4 + param_1 * 8));
  return;
}
