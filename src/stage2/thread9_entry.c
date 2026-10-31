/* thread9_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088668  body 0x80088668..0x80088723  size 191 B
 * body sha256 fb31d54cbcfe0f7bef4dde47250eccbe583878329b6fe15d2b4e90748fdaca3b
 * provider record sha256 938da1fdf6c5860991c5473fe66116c6fe2563460fb0cebfaa60b5ef1f666b72
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void thread9_entry(void)

{
  char cVar1;
  
  osCreateMesgQueue(&DAT_8012bcf8,&DAT_8012bd10,8);
  osCreateMesgQueue(&DAT_8012bd30,&DAT_8012bd48,10);
  DAT_8012bcb0 = '\0';
  do {
    do {
      while (osRecvMesg(&DAT_8012bd30,0,1), DAT_8012bcb0 == '\0') {
        osSendMesg(&DAT_8012bcf8,0,1);
      }
      cVar1 = FUN_800885c0();
    } while (cVar1 != '\0');
    DAT_8012bcb0 = '\0';
    osSendMesg(DAT_8012bcbc,0,1);
  } while( true );
}
