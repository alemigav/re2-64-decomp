/* FUN_8004c564
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c564  body 0x8004c564..0x8004c70b  size 427 B
 * sha256  4b67e6001fe47797e692c59f2a6296c1c62396cef8ae776070900c5f14941a0e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8004c564(short *param_1,uint param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  byte bVar4;
  undefined2 uVar3;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  
  puVar7 = DAT_8010aa8c;
  if (DAT_8010aa8c == (undefined4 *)&UNK_80105a88) {
    uVar1 = *(uint *)(param_3 + 0xd008);
  }
  else {
    puVar5 = DAT_8010aa8c + 3;
    sVar2 = FUN_800844cc((int)*param_1);
    pbVar6 = (byte *)(param_1 + 1);
    bVar4 = *pbVar6;
    do {
      if (bVar4 != 0x20) {
        *puVar7 = 0x80808000;
        *(undefined1 *)((int)puVar5 + -9) = 0;
        puVar5[-2] = param_2 << 0x10 | param_2 >> 0x10;
        uVar3 = FUN_800844cc((*pbVar6 - 0x20 & 0x1f) << 3 | (*pbVar6 - 0x20 & 0xe0) << 6);
        *(undefined2 *)(puVar5 + -1) = uVar3;
        if (*(char *)((int)puVar5 + -3) == '\x10') {
          *(undefined2 *)((int)puVar5 + 6) = 0xb;
        }
        else {
          *(undefined2 *)((int)puVar5 + 6) = 8;
        }
        *(undefined2 *)(puVar5 + 1) = 8;
        *(ushort *)((int)puVar5 + -2) =
             ((short)(((int)sVar2 & 0xf0U) >> 3) + ((short)(char)((ushort)sVar2 >> 8) & 1U)) * 0x40;
        *puVar5 = &DAT_8010b2bc;
        puVar7 = puVar7 + 5;
        puVar5 = puVar5 + 5;
        if (puVar7 == (undefined4 *)&UNK_80105a88) break;
      }
      pbVar6 = pbVar6 + 1;
      bVar4 = *pbVar6;
      param_2 = param_2 + 8;
    } while (bVar4 != 0);
    if (DAT_8010aa8c != puVar7) {
      DAT_800df8b4 = FUN_80043868(DAT_800df8b4,DAT_8010aa8c,puVar7);
    }
    uVar1 = (uint)(pbVar6 + 2) & 0xfffffffe;
    DAT_8010aa8c = puVar7;
  }
  return uVar1;
}
