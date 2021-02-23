#pragma once
#include "Includes.h"
#include "OpCodes.h"
#include "Instruction.h"
#include "Registries.h"
// esp = 0xEC
void AddIndex(int& index, int amount)
{
	index += amount;
}
DWORD CharsToInt(char* bytess, int i, int size)
{
	unsigned char* bytes = (unsigned char*)bytess;
	switch (size)
	{
		case 0:return 0;
		case 1:
			return bytes[i + 1];
		case 2:
			return ((bytes[i + 2] << 8) | (bytes[i + 1]));
		case 3:
			return ((bytes[i + 3] << 16) | (bytes[i + 2] << 8) | (bytes[i + 1]));
		case 4:
			return ((bytes[i + 4] << 24) | (bytes[i + 3] << 16) | (bytes[i + 2] << 8) | (bytes[i + 1]));
		default:
			return ((bytes[i + 4] << 24) | (bytes[i + 3] << 16) | (bytes[i + 2] << 8) | (bytes[i + 1]));
	}
}
string GetOneReg(string input, int reg)
{
	std::vector<string> vect;
	std::stringstream ss(input);

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		vect.push_back(substr);
	}
	vect.at(reg).erase(std::remove(vect.at(reg).begin(), vect.at(reg).end(), ' '), vect.at(reg).end());
	return vect.at(reg);
}
string ReplaceStrs(string input, std::string str, std::string replace)
{
	size_t pos = input.find(str);
	while (pos != std::string::npos)
	{
		input.replace(pos, str.size(), replace);
		pos = input.find(str, pos + replace.size());
	}
	return input;
}

string DetectReg(DWORD input, Instruction instr, bool twooperands, char* bytes, int i)
{
	std::stringstream ss(std::ios_base::app | std::ios_base::in | std::ios_base::out);

	ss << hex << uppercase;
	GetReg(ss, input);
	if (twooperands)
	{
		return ss.str();
	}
	else
	{

		if (ss.str().find(' ') == std::string::npos) // if notfound return
		{
			return ss.str();
		}
		else if (bytes[i+1] >= 0x0040 && bytes[i + 1] <= 0x007F)
		{
			//cout << "hq" << endl;
			string out = ss.str();
			out = ReplaceStrs(out, "]", "");
			ss = stringstream(std::ios_base::app | std::ios_base::in | std::ios_base::out);
			ss << out << " + 0x" << uppercase << hex << static_cast<unsigned int>(bytes[i + instr.bytes[0] + 1]) << "]";
			return ss.str();
		}
		else if (ss.str().find(']') != std::string::npos)
		{
			return "[" + ss.str().substr(ss.str().size() - 4);
		}
		else
		{
			return ss.str().substr(ss.str().size() - 3);
		}

	}
}
void PrintInstruction(char* bytes, int i, Instruction instr)
{
	cout << hex << uppercase<<setfill('0') << setw(4) << i<< " | "/* << (static_cast<unsigned int>(bytes[i]) & 0xff)*/;
	for (int z = 0; z < instr.BytesAfterOpcode+1; z++)
	{
		cout << setfill('0') << setw(2) << (static_cast<unsigned int>(bytes[i + z]) & 0xff) << " ";
	}
	cout << setfill(' ') << setw(17- (instr.BytesAfterOpcode*3)) << "| " << setfill('0') << setw(2) << instr.instructionString;
	if (instr.BytesAfterOpcode > 0)
	{
		cout << " ";
		for (int b = 0; b < instr.operands; b++)
		{
			if (instr.bytes[b])
			{
				cout << DetectReg(CharsToInt(bytes, i + b, instr.bytes[b]), instr, instr.operands > 1 && (!instr.bytes[1]), bytes, i);
				if (bytes[i + 1] >= 0x0040 && bytes[i + 1] <= 0x007F) {
					cout << endl; return;
				}
				if ((b == 0 && instr.operands == 1 & (instr.bytes[1])) || (instr.operands > 1 && (instr.bytes[1]) && b == 0)) cout << ", ";
			}
		}
	}
	cout << endl;
	if (i > 0xA74)Sleep(-1);
	/*if (instr.BytesAfterOpcode > 0)
	{
		cout << " " << setw(4) << setfill('0') << DetectReg(CharsToInt(bytes, i, instr.BytesAfterOpcode)) << endl;
	}
	else cout << endl;*/
}
void Disassemble(char* bytes, int length)
{
	printf( "Disassembling %d bytes.\n", length);
	for (int i = 0; i < length; i++)
	{
		//cout << hex << uppercase << setw(2) << (static_cast<unsigned int>(bytes[i]) & 0xFF) << " ";
		Instruction inst = instructions[(unsigned char)bytes[i]];
		inst.BytesAfterOpcode = inst.bytes[0] + inst.bytes[1];
		int fakei = i;
		AddIndex(fakei, inst.BytesAfterOpcode+1);
		if (!strcmp(instructions[(unsigned char)bytes[fakei]].instructionString.c_str(), "UNDEF"))
		{
			//cout << "next : " << instructions[(unsigned char)bytes[fakei]].instructionString.c_str() << " : " << static_cast<unsigned int>(instructions[(unsigned char)bytes[fakei]].OpCode) << " : size: " << inst.bytes[0] + inst.bytes[1] << endl;
			inst.bytes[1]++;
			inst.BytesAfterOpcode = inst.bytes[0] + inst.bytes[1];
		}
		switch ((unsigned char)bytes[i])
		{
			default:
				PrintInstruction(bytes, i, inst);
		}
		AddIndex(i, inst.BytesAfterOpcode);
	}
}