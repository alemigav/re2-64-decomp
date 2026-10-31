/* FUN_8004944c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004944c  body 0x8004944c..0x800494c3  size 123 B
 * body sha256 0ecf4501fa9046dad85b23747b696d3748018028ea39424a49ceeb226484ce71
 * provider record sha256 2d28c2f9204f9baf648425a09cfa285a4cc3f50c89f56fb5004275a2fd07b78c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004944c(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = (float)func_0x8000d050(param_2);
  uVar2 = func_0x80006be0(param_2);
  param_1[2] = -fVar1;
  *param_1 = uVar2;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = 0x3f800000;
  param_1[6] = fVar1;
  param_1[7] = 0;
  param_1[8] = uVar2;
  return;
}
