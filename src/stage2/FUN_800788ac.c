/* FUN_800788ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800788ac  body 0x800788ac..0x8007898b  size 227 B
 * body sha256 4d4d18926cd0ee253813ababf6f5fca7bfea72c090f019eecf65d44f08c74c6c
 * provider record sha256 b19e399dc2c54219306734c2db3cef33f0f90a8080f81666acdc145de43be5c3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800788ac(int param_1)

{
  short sVar1;
  char *pcVar3;
  char *pcVar2;
  
  pcVar3 = "";
  do {
    pcVar2 = pcVar3 + -8;
    if (param_1 == 0) {
      if ((*pcVar2 == '\x01') && (sVar1 = FUN_80079418((int)pcVar3[-6],0), sVar1 != 0)) {
        FUN_80079344((int)pcVar3[-6],0,0);
        FUN_80079194((int)pcVar3[-6]);
        *pcVar2 = '\x05';
      }
    }
    else if (*pcVar2 == '\x05') {
      FUN_80079344((int)pcVar3[-6],(int)*(short *)(pcVar3 + -4),(int)*(short *)(pcVar3 + -4));
      FUN_80078fc0((int)pcVar3[-6]);
      *pcVar2 = '\x01';
    }
    pcVar3 = pcVar2;
  } while (pcVar2 != &DAT_80119ee4);
  return;
}
