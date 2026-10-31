/* FUN_80062520
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062520  body 0x80062520..0x80062553  size 55 B
 * body sha256 eddcfc047e68d79c6be72585e0a002033a37c7ef9b53a8f287f1eb8b58973fe7
 * provider record sha256 3410e9ee472038b86218116195e8867bf94bc8b7acc3d8add601f4860ac1f9df
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062520(int param_1)

{
  (*(code *)(&PTR_FUN_80111148)[*(byte *)(param_1 + 6)])();
  return;
}
