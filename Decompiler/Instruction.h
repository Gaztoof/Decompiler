#pragma once
#include "Includes.h"

class Instruction
{
public:
	char OpCode;
	char bytes[2];
	char BytesAfterOpcode;
	string instructionString;
	int operands;
	Instruction(char opcode, char Bytesafteropcode, string name, int Operands, char Bytes[2])
	{
		OpCode = opcode;
		bytes[0] = Bytes[0];
		bytes[1] = Bytes[1];
		instructionString = name;
		operands = Operands;
		BytesAfterOpcode = bytes[0] + bytes[1];
	}
	Instruction()
	{
		instructionString = "UNDEF";
		BytesAfterOpcode = 0;
	}
};
Instruction* instructions = new Instruction[256]{};