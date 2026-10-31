/* FUN_80006a6c
 * image   boot (boot), base 0x80000480
 * address 0x80006a6c  body 0x80006a6c..0x80006b1f  size 183 B
 * sha256  add61ddb2f5896bb93251bf644e6301d9c171b4d18f0f28911d5112a237adb13
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80006a6c(undefined1 *param_1,undefined2 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 uVar7;
  uint uVar6;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  uVar6 = 0;
  uVar7 = 0;
  puVar5 = (uint *)&DAT_80014fa0;
  uVar4 = 0;
  if (DAT_80014f9c != 0) {
    puVar3 = param_2 + 1;
    do {
      uVar2 = puVar5[1];
      uVar1 = (*puVar5 >> 8 & 0xc0) >> 4;
      *(char *)((int)puVar3 + 1) = (char)uVar1;
      if (uVar1 == 0) {
        uStack_b = (undefined1)(uVar2 >> 0x10);
        local_c = (undefined1)(uVar2 >> 0x18);
        *param_2 = CONCAT11(uStack_b,local_c);
        uStack_a = (undefined1)(uVar2 >> 8);
        uVar6 = uVar6 | 1 << (uVar4 & 0x1f);
        *(undefined1 *)puVar3 = uStack_a;
      }
      uVar7 = (undefined1)uVar6;
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 2;
      puVar3 = puVar3 + 2;
      param_2 = param_2 + 2;
    } while ((int)uVar4 < (int)(uint)DAT_80014f9c);
  }
  *param_1 = uVar7;
  return;
}
