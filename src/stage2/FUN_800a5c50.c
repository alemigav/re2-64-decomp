/* FUN_800a5c50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c50  body 0x800a5c50..0x800a5c97  size 75 B
 * body sha256 f36624040b7e35fc855558f3ba288ae475b38d0d0d8beca0c02fb629e89557f8
 * provider record sha256 57687243d22820fb9025e1c5d9f182fc00cffd2d45ce95da5302a5df3aecf0ae
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5c50(undefined2 *param_1,int param_2)

{
  undefined2 *puVar1;
  
  puVar1 = param_1 + param_2;
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  func_0x8000efa0(puVar1,8);
  return;
}
