typedef unsigned int undefined4;
extern unsigned int DAT_80163e68;
extern unsigned int DAT_80163ed4;












void FUN_80163c90(int param_1)

{
  undefined4 uVar1;
  
  if (*(unsigned char *)(param_1 + 0x2cc) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x234);
    func_0x80036290(param_1,uVar1,&DAT_80163e68);
    func_0x80036290(param_1,uVar1,&DAT_80163ed4);
    func_0x80036694(param_1);
  }
  return;
}
