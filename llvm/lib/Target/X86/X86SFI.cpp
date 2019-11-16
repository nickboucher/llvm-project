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
        // Log aligning the basic block
        LLVM_DEBUG({
            dbgs() << "Aligning Basic Block: " + MBB.getName() + "\n";
        });
        // Force 32-byte alignment for the basic block
        // Emits '.p2align 5, 0x90' assembly to align using NOOPs
        MBB.setAlignment(Align(32));
    }
    return true;
}


