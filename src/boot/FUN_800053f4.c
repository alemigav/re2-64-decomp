/* FUN_800053f4
 * image   boot (boot), base 0x80000480
 * address 0x800053f4  body 0x800053f4..0x80005437  size 71 B
 * sha256  af5ecced1ea88e62a7d53e1110bd0868fca4fda6713dbd7265fa7f836074bc36
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800053f4(undefined2 *param_1)

{
  _DAT_8001289c = param_1 + 2;
  _DAT_800128a4 = 0x20;
  _DAT_800128a0 = CONCAT22(param_1[1],*param_1);
  return;
}
