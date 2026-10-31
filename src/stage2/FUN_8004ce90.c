/* FUN_8004ce90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce90  body 0x8004ce90..0x8004cec3  size 55 B
 * body sha256 02452f84bac46f1131b9e213505e8aa9ccf3732e69e276c62162539313d89da2
 * provider record sha256 8faef78adcd9f5669553555ef4e4816d38cf63d494c7562bad41101e97a91ae9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce90(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] | 0x40;
  return;
}
