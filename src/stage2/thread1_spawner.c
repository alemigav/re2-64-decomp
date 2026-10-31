/* thread1_spawner
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cb94  body 0x8006cb94..0x8006cc4f  size 191 B
 * sha256  4c51dcbc3a4e66bb3b339fdf41f457119638e6a10d9103647b48e584c9991387
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void thread1_spawner(void)

{
  func_0x8000e4c0(0xfe);
  osCreateMesgQueue(0x80139f10,0x80139ff0,0x14);
  osSetEventMesg(4,0x80139f10,1);
  osSetEventMesg(9,0x80139f10,2);
  osSetEventMesg(6,0x80139f10,10);
  osSetEventMesg(0xe,0x80139f10,8);
  osCreateThread(&DAT_80112a40,1,thread1_entry,0,&DAT_800bdca0,0x28);
  osStartThread(&DAT_80112a40);
  return;
}
