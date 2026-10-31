/* FUN_8005eb98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005eb98  body 0x8005eb98..0x8005ecb3  size 287 B
 * body sha256 819861e405390871652946d2e6fc66b2b0487412fb962608095bef9ae47a0bd6
 * provider record sha256 e5de3e18be3b8d5cb3e6e159c09bf3afda20df45c909df1fdd48b76d33891023
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005eb98(int param_1)

{
  int iVar1;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 0x1e9) == '\x02') {
    local_20 = 0x82;
    local_1e = 0x2da;
    local_1c = 0;
    iVar1 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1001000,0,iVar1,&local_20);
    local_1e = 0x118;
    FUN_80037780(0x1041000,0,iVar1,&local_20);
    FUN_80037780(0x1061000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar1,
                 &local_20);
    FUN_80037780(0x30a0c00,0,iVar1,&local_20);
    local_1e = 0x33e;
    FUN_80037780(0x30c1000,0,iVar1,&local_20);
    local_1e = 0x38e;
    local_14 = 0x400;
    local_18 = 0;
    local_16 = 0;
    FUN_80037c50(0x1073000,0,iVar1,&local_20,&local_18);
  }
  return;
}
