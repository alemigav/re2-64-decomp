/* FUN_80071b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071b3c  body 0x80071b3c..0x80071b93  size 91 B
 * body sha256 259e3cffda10965442d645e9320c396e0d09bd00a55c8f889782b427f9f61ee6
 * provider record sha256 4d81a50afbfb7cd88275155db3a2e95501b6b1b45c95e27b9cbe083795290f4d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071b3c(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
