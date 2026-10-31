/* FUN_80059b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059b04  body 0x80059b04..0x80059b5f  size 95 B
 * body sha256 40a4b2eab97db74001e3ca18e9fc06c40bb939a8d254945ceb902c883893ef3d
 * provider record sha256 0f973a1794d0f3b53901e48f933e2b4433ef2ad124eb75d5b1f5d93014764b20
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059b04(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  (*(code *)(&PTR_FUN_8010dd00)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
