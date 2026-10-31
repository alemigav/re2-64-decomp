/* FUN_8005df98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005df98  body 0x8005df98..0x8005e0f7  size 355 B
 * sha256  a85a6a79db80a0a37d48794d8ea3d520f2ac0b4af49ff8e6c9abbfd2d8ffa69f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005df98(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x82;
    local_16 = 900;
    local_14 = 0xfff6;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a1800,0,iVar2,&local_18);
    FUN_80037780(0x1002000,0,iVar2,&local_18);
    local_16 = 0x44c;
    FUN_80037780(0x1023000,0,iVar2,&local_18);
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
  DAT_800e110c = DAT_800e110c & 0xffffff7f;
  return;
}
