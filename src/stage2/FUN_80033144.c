/* FUN_80033144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033144  body 0x80033144..0x8003315f  size 31 B
 * body sha256 d153acc6ea2fdc67ce50694e9a0e6e14f6812c6fa19ebc308fc6da0ece1e9a12
 * provider record sha256 d3f9d9dc6e1beb0b8ffd778aa6fc8e4c845a56f3ad242fe368b873d1e91f7ee3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033144(int param_1,int param_2)

{
  return (((int)*(short *)(param_2 + 0x66) - (int)*(short *)(param_1 + 0x66)) + 0x400U & 0xfff) <
         0x800;
}
