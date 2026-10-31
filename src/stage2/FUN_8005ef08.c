/* FUN_8005ef08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ef08  body 0x8005ef08..0x8005efc3  size 191 B
 * sha256  dc15be2c1c509a7888ff6d5df066dd22565bc627c711e0e701c4f8685c3a2ab4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ef08(int param_1)

{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 0x1e9) == '\x01') {
    local_18 = 0;
    local_16 = 0x44c;
    local_14 = 0;
    iVar1 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1002000,0,iVar1,&local_18);
    FUN_80037780(0x20d1000,(int)*(short *)(param_1 + 0x66),iVar1,&local_18);
    FUN_80037780(0x30a1a00,0,iVar1,&local_18);
    local_18 = 300;
    local_16 = 0xfc7c;
    FUN_80037780(0x30a1500,0,iVar1,&local_18);
  }
  return;
}
