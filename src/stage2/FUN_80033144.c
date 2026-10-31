/* FUN_80033144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033144  body 0x80033144..0x8003315f  size 31 B
 * body sha256 d153acc6ea2fdc67ce50694e9a0e6e14f6812c6fa19ebc308fc6da0ece1e9a12
 * provider record sha256 15a478097da119b245ff677e93b433a0897f469f89fb3f57d6b971fa6718b797
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033144(int param_1,int param_2)

{
  return (((int)*(short *)(param_2 + 0x66) - (int)*(short *)(param_1 + 0x66)) + 0x400U & 0xfff) <
         0x800;
}
