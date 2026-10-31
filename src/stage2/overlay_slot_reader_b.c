/* overlay_slot_reader_b
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cd08  body 0x8004cd08..0x8004cd53  size 79 B
 * body sha256 c4975c5534f85f9b5c5acdf0c8fff28172d3d196e9fba699b45200572e00368b
 * provider record sha256 e3484c7f423e2c797deef539737b98683b556c027ff37ae77beb092b2be8083e
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
