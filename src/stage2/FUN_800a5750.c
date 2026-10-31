/* FUN_800a5750
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5750  body 0x800a5750..0x800a5793  size 71 B
 * sha256  c7ed4370e0c3dd97c12ae30c60c3f29ed72489d3a1f20194b46bc405996c113f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5750(void)

{
  if (DAT_80143f4d != '\0') {
    (*_DAT_80143ff4)();
    func_0x80011390();
    DAT_80143f4d = '\0';
  }
  return;
}
