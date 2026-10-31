/* FUN_8002e848
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e848  body 0x8002e848..0x8002e86b  size 39 B
 * body sha256 ab6eabef361891cf4da9f7efd49a8acc1e680ebd53ec4f97284e21c80c9e5036
 * provider record sha256 d4615989831d88da80b6f1d64e033585620a1d26848a4c790dfbeca3533d13e2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e848(int *param_1)

{
  undefined1 auStack_d0 [200];
  
  (**(code **)(*param_1 + 0xc))(param_1,auStack_d0);
  return;
}
