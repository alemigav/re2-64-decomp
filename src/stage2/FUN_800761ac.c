/* FUN_800761ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800761ac  body 0x800761ac..0x800762af  size 263 B
 * sha256  c06b0493fa6755a2fed914f4f80278186dbb8155e2e1abf2ad846e7912298dd1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800761ac(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_800c52dc + 0x3100;
  if (-1 < DAT_80119ea9) {
    FUN_80075608(5,1);
    DAT_80119ea9 = -1;
  }
  iVar1 = (param_1 & 0xff) * 2;
  do {
    func_0x80004cfc(*(undefined2 *)(&DAT_80115e64 + iVar1),iVar2,1,"ARMS EDT");
    DAT_80119ea9 = FUN_800752dc(*(undefined2 *)(&DAT_80115df0 + iVar1),5,1);
    DAT_8011a298 = (&PTR_s__80115a30_0x68_80115e18)[param_1 & 0xff];
  } while (DAT_80119ea9 == -1);
  return;
}
