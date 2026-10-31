/* overlay_slot_reader
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cca8  body 0x8004cca8..0x8004cd07  size 99 B
 * body sha256 965d158b8573194f4e2bea326a0547b1baf00f2be03fbe78acba03f7617979b5
 * provider record sha256 bdbf80c53a63858fa488dd9c89217cb1b701ae1e3f93a39aa617c04912fd107a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 overlay_slot_reader(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = cart_record((&DAT_8010b2e0)[param_2 * 8]);
  uVar1 = overlay_inflate(uVar1);
  FUN_8004cd54(param_1,*(undefined4 *)(&DAT_8010b2e4 + param_2 * 8));
  return uVar1;
}
