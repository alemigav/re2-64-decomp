/* FUN_80087c60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087c60  body 0x80087c60..0x80087cf7  size 155 B
 * sha256  c8ffaa5e397e87efbdbbc990e5a59913f7ed789f4afd3e10c8fc89d7bb1b530a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087c60(undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[1];
  if ((&DAT_8012a034)[*piVar2] == '\x02') {
    (&DAT_8012a034)[*piVar2] = '\x03';
    *param_1 = 8;
    uVar1 = piVar2[1];
    if (uVar1 < 0x65) {
      FUN_80087af0(param_1,param_1,piVar2,uVar1);
    }
    else {
      func_0x8000cec0(0x8013a320,param_1,0,uVar1,0,0,0x8013a230,param_1);
    }
  }
  return;
}
