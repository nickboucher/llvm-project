//===----------------------------------------------------------------------===//
//
// This file defines the pass which will apply Software Fault Isolation
// (SFI) x86 restrictions
//
//===----------------------------------------------------------------------===//


#include "X86.h"

using namespace llvm;

#define DEBUG_TYPE "x86-sfi"

FunctionPass *llvm::createX86SFIPass() {
  return nullptr;
}
