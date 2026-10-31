/* FUN_8005aaf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005aaf8  body 0x8005aaf8..0x8005ab0f  size 27 B
 * body sha256 34d3f1d6b71cb93f434ebea274f06e9ba5670fa14914d8498ffc72853773a2b5
 * provider record sha256 ca0e6288590ce7566970e3338a9280922938a76cc7d4e1b012bde8b7f63fa0c7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005aaf8(int param_1)

{
  *(char *)(param_1 + 0x1a3) = *(char *)(param_1 + 0x1a3) - (char)DAT_80111160;
  return;
}
