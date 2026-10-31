/* FUN_80043930
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043930  body 0x80043930..0x80043987  size 91 B
 * body sha256 15fff46da663507f97986f20dc116f5bf78ea1db9e30dd6bdf261191ab386314
 * provider record sha256 0e8c2505d3bd3acb4bb41830d92357e66d848dd767c6245d4eb451da9b32e724
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80043930(undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = param_2[2];
  local_14 = param_2[3];
  local_10 = 0x80008;
  FUN_80043988(param_1,&local_20,0,0);
  return;
}
