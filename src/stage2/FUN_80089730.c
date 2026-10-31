/* FUN_80089730
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089730  body 0x80089730..0x800897d3  size 167 B
 * body sha256 9b2e5f611fe2ee328a81fbdab3cc49d61e8753c8dce639805fb097fa6680d651
 * provider record sha256 98fdcd36485e8de95de88f7150001df1c1f2c34bece63892e42920cc9390e367
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089730(uint *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int local_20;
  int local_1c;
  int local_18;
  
  puVar1 = (undefined4 *)param_1[0x8d];
  FUN_80040e58(param_1 + 0x19,param_1 + 5);
  if ((*param_1 & 0x800) != 0) {
    local_20 = (int)*(short *)((int)param_1 + 0x212);
    local_1c = (int)*(short *)((int)param_1 + 0x212);
    local_18 = (int)*(short *)((int)param_1 + 0x212);
    FUN_80040d2c(param_1 + 5,&local_20);
  }
  cVar2 = *(char *)((int)param_1 + 0x1a3);
  do {
    FUN_80088e34(param_1,puVar1,*puVar1,puVar1 + 0xe);
    cVar2 = cVar2 + -1;
    puVar1 = puVar1 + 0x5e;
  } while (cVar2 != '\0');
  return;
}
