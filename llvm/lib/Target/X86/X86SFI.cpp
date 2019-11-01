//===----------------------------------------------------------------------===//
//
// This file defines the pass which will apply Software Fault Isolation
// (SFI) x86 restrictions
//
//===----------------------------------------------------------------------===//


#include "X86.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "X86Subtarget.h"

using namespace llvm;

#define DEBUG_TYPE "x86-sfi"


class X86SFIPass : public MachineFunctionPass {
public:
    X86SFIPass(): MachineFunctionPass(ID) {}
    
    bool runOnMachineFunction(MachineFunction &MF) override;
    
private:
    StringRef getPassName() const override {
        return "X86 SFI Pass";
    }
    static char ID;
};

char X86SFIPass::ID = 42;


FunctionPass *llvm::createX86SFIPass() {
    return new X86SFIPass();
}

bool X86SFIPass::runOnMachineFunction(MachineFunction &MF) {
    for (MachineBasicBlock &MBB : MF) {
        LLVM_DEBUG({
            dbgs() << "Machine Basic Block: ";
            dbgs() << MBB.getFullName();
            dbgs() << "\n";
        });
    }
    return true;
}


