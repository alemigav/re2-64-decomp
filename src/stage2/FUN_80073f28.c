/* FUN_80073f28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073f28  body 0x80073f28..0x80073f63  size 63 B
 * sha256  01276a6e5d3aa1606d3d6cad363c34369924acabda4a7cfbdf25d38207fffde8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073f28(undefined2 *param_1)

{
  FUN_8004ac04(0,param_1[1] + 0x300,*param_1,(uint)(ushort)param_1[2] << 0x10);
  return 0;
}
