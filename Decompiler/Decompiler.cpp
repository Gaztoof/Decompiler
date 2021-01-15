#include "Includes.h"
#include "Disassembler.h"
#include "OpCodes.h"
#include "Instruction.h"
void AddInstruction(int opcode, int bytesafteropcode, string name, int operand, char Bytes[2])
{
	instructions[opcode] = Instruction(opcode, bytesafteropcode, name, operand, Bytes);
}
int main(int argc, char** argv) {
	for (int i = 0; i < 256; i++)
	{
		instructions[i] = Instruction(i, 0, "UNDEF", 0, new char[] {0, 0});
	}
	AddInstruction(0xE9, 4, "jmp", 1, new char[] {4, 0});
	AddInstruction(0x90, 0, "nop", 0, new char[] {0, 0});
	AddInstruction(0xCC, 0, "int3", 0, new char[] {0, 0});
	AddInstruction(0x55, 0, "push ebp", 0, new char[] {0, 0});
	AddInstruction(0x5D, 0, "pop ebp", 0, new char[] {0, 0});
	AddInstruction(0xC3, 0, "ret", 0, new char[] {0, 0});
	AddInstruction(0x81, 5, "sub", 2, new char[] {1, 4});
	AddInstruction(0x53, 0, "push ebx", 0, new char[] {0, 0});
	AddInstruction(0x54, 0, "push ecx", 0, new char[] {0, 0});
	AddInstruction(0x56, 0, "push esi", 0, new char[] {0, 0});
	AddInstruction(0x57, 0, "push edi", 0, new char[] {0, 0});
	AddInstruction(0x8D, 5, "lea", 2, new char[] {1, 4});
	AddInstruction(0xB8, 4, "mov eax,", 1, new char[] {4, 0});
	AddInstruction(0xB9, 4, "mov ecx,", 1, new char[] {4, 0});
	AddInstruction(0x5F, 0, "pop edi", 0, new char[] {0, 0});
	AddInstruction(0x5E, 0, "pop esi", 0, new char[] {0, 0});
	AddInstruction(0x5B, 0, "pop ebx", 0, new char[] {0, 0});
	AddInstruction(0x81, 5, "add", 2, new char[] {1, 4});
	AddInstruction(0x3B, 1, "cmp ebp,", 1, new char[] {1, 0});
	AddInstruction(0xF3, 1, "repe", 1, new char[] {1, 0}); // search that cuz 0x5b can be mov esp and mov ebp at same time
	AddInstruction(0x3C, 1, "cmp al,", 1, new char[] {1, 4});
	AddInstruction(0x3D, 1, "cmp eax,", 1, new char[] {1, 4});
	AddInstruction(0x2D, 1, "sub eax,", 1, new char[] {1, 4});
	AddInstruction(0x2D, 4, "push", 1, new char[] {4,0});
	AddInstruction(0x83, 4, "add", 2, new char[] {1,1});
	AddInstruction(0x33, 1, "xor", 2, new char[] {1,0});
	AddInstruction(0x68, 4, "push", 1, new char[] {4,0});

	AddInstruction(0x8B, 1, "mov", 2, new char[] {1,0});
	AddInstruction(0x89, 1, "mov", 2, new char[] {1,1});
	AddInstruction(0x81, 5, "add", 2, new char[] {1,4});
	AddInstruction(0x3B, 1, "cmp", 2, new char[] {1, 0});
	AddInstruction(0xE8, 4, "call", 1, new char[] {4, 0});
	AddInstruction(0x85, 4, "test", 2, new char[] {1, 0});
	AddInstruction(0x74, 4, "test", 1, new char[] {1, 0});
	AddInstruction(0x39, 4, "cmp", 2, new char[] {1, 0});
	AddInstruction(0x7E, 4, "jle", 1, new char[] {1, 0});
	AddInstruction(0x75, 4, "jne", 1, new char[] {1, 0});
	AddInstruction(0x03, 4, "add", 1, new char[] {1, 0});
	AddInstruction(0xFF, 4, "push", 1, new char[] {3, 0});
	//AddInstruction(0xFF, 4, "push eax", 1, new char[] {0, 0});
	AddInstruction(0x47, 1, "inc", 1, new char[] {1, 0});
	AddInstruction(0x7C, 4, "jl", 1, new char[] {1, 0});
	AddInstruction(0xC2, 4, "ret", 1, new char[] {2, 0});
	AddInstruction(0x4F, 4, "dec edi", 1, new char[] {0, 0});
	AddInstruction(0x50, 4, "push eax", 1, new char[] {0, 0});

	int i = 0;
	HANDLE hMapObject, hFile;
	LPVOID lpBase;
	PIMAGE_DOS_HEADER dosHeader;
	PIMAGE_NT_HEADERS ntHeader;
	IMAGE_FILE_HEADER header;
	IMAGE_OPTIONAL_HEADER opHeader;
	PIMAGE_SECTION_HEADER pSecHeader;
	hFile = CreateFile("C:\\Users\\frgli\\source\\repos\\Testing1\\Debug\\Testing1.exe", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	hMapObject = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	lpBase = MapViewOfFile(hMapObject, FILE_MAP_READ, 0, 0, 0);
	dosHeader = (PIMAGE_DOS_HEADER)lpBase;
	ntHeader = (PIMAGE_NT_HEADERS)((DWORD)(dosHeader)+(dosHeader->e_lfanew));
	if (ntHeader->Signature == IMAGE_NT_SIGNATURE) {
		header = ntHeader->FileHeader;
		if ((header.Characteristics & 0x0002) == 0x0002) printf("Executable Image ,");
		if ((header.Characteristics & 0x0020) == 0x0020) printf("Application can address > 2GB ,");
		if ((header.Characteristics & 0x1000) == 0x1000) printf("System file (Kernel Mode Driver(I think)) ,");
		if ((header.Characteristics & 0x2000) == 0x2000) printf("Dll file ,");
		if ((header.Characteristics & 0x4000) == 0x4000) printf("Application runs only in Uniprocessor ,");
		opHeader = ntHeader->OptionalHeader;

		for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), i = 0; i < ntHeader->FileHeader.NumberOfSections; i++, pSecHeader++) {
			if (!strcmp(".text", (const char*)pSecHeader->Name))
				Disassemble((char*)((DWORD)dosHeader + pSecHeader->PointerToRawData), pSecHeader->SizeOfRawData);
		}
	}
	UnmapViewOfFile(lpBase);
	CloseHandle(hMapObject);
}
