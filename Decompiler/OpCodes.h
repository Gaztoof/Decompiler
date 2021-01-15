#pragma once
#include "Includes.h"
enum Kinds
{
	ib,
	iw,
	id
};
class OpCode
{
public:
	char Opcode;
	Kinds kind;
	string OpcodeString;
	OpCode(char opcode, int Kind, string Opcodestring) {
		Opcode = opcode;
		kind = (Kinds)Kind;
		OpcodeString = Opcodestring;
	};
};
struct OpCodes
{
	OpCode CMPAX = OpCode(0x3D, Kinds::iw, "CMP");
};