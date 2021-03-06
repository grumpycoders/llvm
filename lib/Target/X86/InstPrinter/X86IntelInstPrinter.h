//= X86IntelInstPrinter.h - Convert X86 MCInst to assembly syntax -*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints an X86 MCInst to Intel style .s file syntax.
//
//===----------------------------------------------------------------------===//

#ifndef X86_INTEL_INST_PRINTER_H
#define X86_INTEL_INST_PRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {

class MCOperand;
  
class X86IntelInstPrinter : public MCInstPrinter {
public:
  X86IntelInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                      const MCRegisterInfo &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

  virtual void printRegName(raw_ostream &OS, unsigned RegNo) const;
  virtual void printInst(const MCInst *MI, raw_ostream &OS, StringRef Annot);
  
  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  virtual void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  virtual void printMemReference(const MCInst *MI, unsigned Op, raw_ostream &O);
  virtual void printSSECC(const MCInst *MI, unsigned Op, raw_ostream &O);
  virtual void printAVXCC(const MCInst *MI, unsigned Op, raw_ostream &O);
  virtual void printPCRelImm(const MCInst *MI, unsigned OpNo, raw_ostream &O);
  virtual void printMemOffset(const MCInst *MI, unsigned OpNo, raw_ostream &O);

  void printopaquemem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "opaque ptr ";
    printMemReference(MI, OpNo, O);
  }
  
  void printi8mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "byte ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi16mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "word ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi32mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "dword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi64mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "qword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi128mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "xmmword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi256mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "ymmword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printi512mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "zmmword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf32mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "dword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf64mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "qword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf80mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "xword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf128mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "xmmword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf256mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "ymmword ptr ";
    printMemReference(MI, OpNo, O);
  }
  void printf512mem(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "zmmword ptr ";
    printMemReference(MI, OpNo, O);
  }

  void printMemOffs8(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "byte ptr ";
    printMemOffset(MI, OpNo, O);
  }
  void printMemOffs16(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "word ptr ";
    printMemOffset(MI, OpNo, O);
  }
  void printMemOffs32(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "dword ptr ";
    printMemOffset(MI, OpNo, O);
  }
  void printMemOffs64(const MCInst *MI, unsigned OpNo, raw_ostream &O) {
    O << "qword ptr ";
    printMemOffset(MI, OpNo, O);
  }
};
  
}

#endif
