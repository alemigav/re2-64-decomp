/* FUN_80088388
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088388  body 0x80088388..0x80088497  size 275 B
 * body sha256 10908cce937a13103957a050e8b57650a7a6400803329af9d77cafa3d51cdc63
 * provider record sha256 d6d56f0935af1e7321d49e3c77ea574047c868a5b6f80efe598c9d29e7ba7d6b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
ushort * FUN_80088388(int param_1,ushort param_2)

{
  ushort *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  uint uVar6;
  ushort *puVar7;
  
  puVar7 = (ushort *)0x0;
  if (param_1 != 0) {
    uVar3 = func_0x800072e0();
    uVar6 = param_1 + 0xfU & 0xfffffff0;
    puVar5 = (ushort *)0x0;
    uVar2 = *DAT_8012bae0;
    puVar4 = DAT_8012bae0;
    while ((uVar2 & 8) == 0) {
      if (((*puVar4 & 1) != 0) && (uVar6 <= *(uint *)(puVar4 + 2))) {
        puVar5 = puVar4;
      }
      puVar1 = (ushort *)((int)puVar4 + *(int *)(puVar4 + 2) + 0x10);
      puVar4 = (ushort *)((int)puVar4 + *(int *)(puVar4 + 2) + 0x10);
      uVar2 = *puVar1;
    }
    if (puVar5 == (ushort *)0x0) {
      func_0x80007300(uVar3);
      trap(0x407);
    }
    else {
      puVar7 = puVar5 + 8;
      *puVar5 = 2;
      puVar5[1] = param_2;
      if ((uVar6 != *(uint *)(puVar5 + 2)) && (0x1f < *(uint *)(puVar5 + 2) - uVar6)) {
        *(undefined2 *)((int)puVar7 + uVar6) = 1;
        *(uint *)((undefined2 *)((int)puVar7 + uVar6) + 2) = (*(int *)(puVar5 + 2) - uVar6) + -0x10;
        *(uint *)(puVar5 + 2) = uVar6;
      }
    }
    func_0x80007300(uVar3);
  }
  return puVar7;
}
