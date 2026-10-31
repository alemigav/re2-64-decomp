/* FUN_8003b238
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b238  body 0x8003b238..0x8003b2a3  size 111 B
 * body sha256 1f21048063d5a21f28a2994674cce6b2637b8b3e01cd0805b2a51888eba9b0ce
 * provider record sha256 b4c4cdece38771d9eaa99c1f67e34b879972f26280c2b6e9f05e613a3450d814
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b238(void)

{
  FUN_80038a20(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x96) / 100 | 0x30b0000,0,&DAT_800e9028,
               DAT_800ebb94 + 0x34);
  return;
}
