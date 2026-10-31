/* FUN_8005de80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005de80  body 0x8005de80..0x8005df97  size 283 B
 * sha256  3da87d5bf9c0bb1b16a77965814b9c13049a9e543b668af4ed17c590f8b4168b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005de80(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x6e;
    local_16 = 0x29e;
    local_14 = 0xfff6;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a1400,0,iVar2,&local_18);
    FUN_80037780(0x1001d00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x04') {
    local_18 = 0x14a;
    local_16 = 0x32;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x2000900,(int)((DAT_800e1196 + 0x694) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  return;
}
