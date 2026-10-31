/* FUN_800aca08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aca08  body 0x800aca08..0x800acae3  size 223 B
 * sha256  59fb6e495b08103575dfec1fa37b836a84ccc2af3dd67ef940eb6eb7fb94a48d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
short FUN_800aca08(int param_1,char param_2)

{
  short sVar1;
  char cVar2;
  
  cVar2 = param_2;
  switch(param_2) {
  case -0x80:
    cVar2 = -0x80;
    break;
  case -0x7f:
    cVar2 = -0x7e;
    break;
  case -0x7e:
    cVar2 = -0x60;
    break;
  case -0x7d:
    cVar2 = -0x5f;
    break;
  case -0x7c:
    cVar2 = -0x7d;
    break;
  case -0x7b:
    cVar2 = -0x7c;
  }
  if (cVar2 == -0x60) {
    sVar1 = *(short *)(param_1 + 0x170);
  }
  else {
    if (cVar2 != -0x5f) {
      if (*(char *)(param_1 + 0x4a) == -1) {
        return 0;
      }
      sVar1 = FUN_800ac0c8(param_2,*(char *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b));
      return sVar1;
    }
    sVar1 = *(short *)(param_1 + 0x17c);
  }
  return sVar1 * 2 + 0x2000;
}
