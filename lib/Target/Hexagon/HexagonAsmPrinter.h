//===-- HexagonAsmPrinter.h - Print machine code to an Hexagon .s file ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Hexagon Assembly printer class.
//
//===----------------------------------------------------------------------===//

#ifndef HEXAGONASMPRINTER_H
#define HEXAGONASMPRINTER_H

#include "Hexagon.h"
#include "HexagonTargetMachine.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {
  class HexagonAsmPrinter : public AsmPrinter {
    const HexagonSubtarget *Subtarget;

  public:
    explicit HexagonAsmPrinter(TargetMachine &TM, MCStreamer &Streamer)
      : AsmPrinter(TM, Streamer) {
      Subtarget = &TM.getSubtarget<HexagonSubtarget>();
    }

    virtual const char *getPassName() const {
      return "Hexagon Assembly Printer";
    }

    bool isBlockOnlyReachableByFallthrough(const MachineBasicBlock *MBB) const;

    virtual void EmitInstruction(const MachineInstr *MI);

    void printOperand(const MachineInstr *MI, unsigned OpNo, raw_ostream &O);
    bool PrintAsmOperand(const MachineInstr *MI, unsigned OpNo,
                         unsigned AsmVariant, const char *ExtraCode,
                         raw_ostream &OS);
    bool PrintAsmMemoryOperand(const MachineInstr *MI, unsigned OpNo,
                               unsigned AsmVariant, const char *ExtraCode,
                               raw_ostream &OS);

    static const char *getRegisterName(unsigned RegNo);
  };

} // end of llvm namespace

#endif
