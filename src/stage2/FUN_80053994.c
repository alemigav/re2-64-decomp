/* FUN_80053994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053994  body 0x80053994..0x8005399f  size 15 B
 * body sha256 14113945b5fa3b9216f88d660a9a995256055988797d4061204e0ddf603fa2fa
 * provider record sha256 fa052f5bafadad114fcd7fc66af0b4ae0db94029c530ae9f1671b02c7f94a5c2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80053994(uint param_1)

{
  return (param_1 & 0xff) + 0x3f;
}
