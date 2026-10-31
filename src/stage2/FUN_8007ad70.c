/* FUN_8007ad70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ad70  body 0x8007ad70..0x8007adb3  size 71 B
 * body sha256 ffdb4be6c5ece141eb0051861284eb77a1a0556d9fe5a873e7720171a6cabee9
 * provider record sha256 9be7401b8d001f7d7d34ae592c62f8d36af7aa9867567fd0657f7301e671566b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ad70(int param_1)

{
  (*(code *)(&PTR_FUN_8011aae0)[(*(byte *)(param_1 + 8) - 0x40) * 8 + (uint)*(byte *)(param_1 + 5)])
            ();
  return;
}
