#pragma once
#include "Includes.h"
void GetReg(stringstream& ss, DWORD input)
{
	switch (input)
	{
		/*case 0xEC:
			ss << "esp";
			break;
		case 0xAB:
			ss << "stosd";
			break;
		case 0xC4:
			ss << "esp";
			break;
		case 0xE5:
			ss << "ebp";
			break;
		case 0xBD:
			ss << "edi";
			break;*/
	case 0x0000:
		ss << "eax, [eax]";
		break;

	case 0x0003:
		ss << "eax, [ebx]";
		break;

	case 0x0001:
		ss << "eax, [ecx]";
		break;

	case 0x0002:
		ss << "eax, [edx]";
		break;

	case 0x0005:
		ss << "eax, [ebp]";
		break;

	case 0x0004:
		ss << "eax, [esp]";
		break;

	case 0x0006:
		ss << "eax, [esi]";
		break;

	case 0x0007:
		ss << "eax, [edi]";
		break;

	case 0x0018:
		ss << "ebx, [eax]";
		break;

	case 0x001B:
		ss << "ebx, [ebx]";
		break;

	case 0x0019:
		ss << "ebx, [ecx]";
		break;

	case 0x001A:
		ss << "ebx, [edx]";
		break;

	case 0x001D:
		ss << "ebx, [ebp]";
		break;

	case 0x001C:
		ss << "ebx, [esp]";
		break;

	case 0x001E:
		ss << "ebx, [esi]";
		break;

	case 0x001F:
		ss << "ebx, [edi]";
		break;

	case 0x0008:
		ss << "ecx, [eax]";
		break;

	case 0x000B:
		ss << "ecx, [ebx]";
		break;

	case 0x0009:
		ss << "ecx, [ecx]";
		break;

	case 0x000A:
		ss << "ecx, [edx]";
		break;

	case 0x000D:
		ss << "ecx, [ebp]";
		break;

	case 0x000C:
		ss << "ecx, [esp]";
		break;

	case 0x000E:
		ss << "ecx, [esi]";
		break;

	case 0x000F:
		ss << "ecx, [edi]";
		break;

	case 0x0010:
		ss << "edx, [eax]";
		break;

	case 0x0013:
		ss << "edx, [ebx]";
		break;

	case 0x0011:
		ss << "edx, [ecx]";
		break;

	case 0x0012:
		ss << "edx, [edx]";
		break;

	case 0x0015:
		ss << "edx, [ebp]";
		break;

	case 0x0014:
		ss << "edx, [esp]";
		break;

	case 0x0016:
		ss << "edx, [esi]";
		break;

	case 0x0017:
		ss << "edx, [edi]";
		break;

	case 0x0028:
		ss << "ebp, [eax]";
		break;

	case 0x002B:
		ss << "ebp, [ebx]";
		break;

	case 0x0029:
		ss << "ebp, [ecx]";
		break;

	case 0x002A:
		ss << "ebp, [edx]";
		break;

	case 0x002D:
		ss << "ebp, [ebp]";
		break;

	case 0x002C:
		ss << "ebp, [esp]";
		break;

	case 0x002E:
		ss << "ebp, [esi]";
		break;

	case 0x002F:
		ss << "ebp, [edi]";
		break;

	case 0x0020:
		ss << "esp, [eax]";
		break;

	case 0x0023:
		ss << "esp, [ebx]";
		break;

	case 0x0021:
		ss << "esp, [ecx]";
		break;

	case 0x0022:
		ss << "esp, [edx]";
		break;

	case 0x0025:
		ss << "esp, [ebp]";
		break;

	case 0x0024:
		ss << "esp, [esp]";
		break;

	case 0x0026:
		ss << "esp, [esi]";
		break;

	case 0x0027:
		ss << "esp, [edi]";
		break;

	case 0x0030:
		ss << "esi, [eax]";
		break;

	case 0x0033:
		ss << "esi, [ebx]";
		break;

	case 0x0031:
		ss << "esi, [ecx]";
		break;

	case 0x0032:
		ss << "esi, [edx]";
		break;

	case 0x0035:
		ss << "esi, [ebp]";
		break;

	case 0x0034:
		ss << "esi, [esp]";
		break;

	case 0x0036:
		ss << "esi, [esi]";
		break;

	case 0x0037:
		ss << "esi, [edi]";
		break;

	case 0x0038:
		ss << "edi, [eax]";
		break;

	case 0x003B:
		ss << "edi, [ebx]";
		break;

	case 0x0039:
		ss << "edi, [ecx]";
		break;

	case 0x003A:
		ss << "edi, [edx]";
		break;

	case 0x003D:
		ss << "edi, [ebp]";
		break;

	case 0x003C:
		ss << "edi, [esp]";
		break;

	case 0x003E:
		ss << "edi, [esi]";
		break;

	case 0x003F:
		ss << "edi, [edi]";
		break;


	case 0xAB:
		ss << "stosd";
		break;

	case 0x0040:
		ss << "eax, [eax]";
		break;

	case 0x0043:
		ss << "eax, [ebx]";
		break;

	case 0x0041:
		ss << "eax, [ecx]";
		break;

	case 0x0042:
		ss << "eax, [edx]";
		break;

	case 0x0045:
		ss << "eax, [ebp]";
		break;

	case 0x0044:
		ss << "eax, [esp]";
		break;

	case 0x0046:
		ss << "eax, [esi]";
		break;

	case 0x0047:
		ss << "eax, [edi]";
		break;

	case 0x0058:
		ss << "ebx, [eax]";
		break;

	case 0x005B:
		ss << "ebx, [ebx]";
		break;

	case 0x0059:
		ss << "ebx, [ecx]";
		break;

	case 0x005A:
		ss << "ebx, [edx]";
		break;

	case 0x005D:
		ss << "ebx, [ebp]";
		break;

	case 0x005C:
		ss << "ebx, [esp]";
		break;

	case 0x005E:
		ss << "ebx, [esi]";
		break;

	case 0x005F:
		ss << "ebx, [edi]";
		break;

	case 0x0048:
		ss << "ecx, [eax]";
		break;

	case 0x004B:
		ss << "ecx, [ebx]";
		break;

	case 0x0049:
		ss << "ecx, [ecx]";
		break;

	case 0x004A:
		ss << "ecx, [edx]";
		break;

	case 0x004D:
		ss << "ecx, [ebp]";
		break;

	case 0x004C:
		ss << "ecx, [esp]";
		break;

	case 0x004E:
		ss << "ecx, [esi]";
		break;

	case 0x004F:
		ss << "ecx, [edi]";
		break;

	case 0x0050:
		ss << "edx, [eax]";
		break;

	case 0x0053:
		ss << "edx, [ebx]";
		break;

	case 0x0051:
		ss << "edx, [ecx]";
		break;

	case 0x0052:
		ss << "edx, [edx]";
		break;

	case 0x0055:
		ss << "edx, [ebp]";
		break;

	case 0x0054:
		ss << "edx, [esp]";
		break;

	case 0x0056:
		ss << "edx, [esi]";
		break;

	case 0x0057:
		ss << "edx, [edi]";
		break;

	case 0x0068:
		ss << "ebp, [eax]";
		break;

	case 0x006B:
		ss << "ebp, [ebx]";
		break;

	case 0x0069:
		ss << "ebp, [ecx]";
		break;

	case 0x006A:
		ss << "ebp, [edx]";
		break;

	case 0x006D:
		ss << "ebp, [ebp]";
		break;

	case 0x006C:
		ss << "ebp, [esp]";
		break;

	case 0x006E:
		ss << "ebp, [esi]";
		break;

	case 0x006F:
		ss << "ebp, [edi]";
		break;

	case 0x0060:
		ss << "esp, [eax]";
		break;

	case 0x0063:
		ss << "esp, [ebx]";
		break;

	case 0x0061:
		ss << "esp, [ecx]";
		break;

	case 0x0062:
		ss << "esp, [edx]";
		break;

	case 0x0065:
		ss << "esp, [ebp]";
		break;

	case 0x0064:
		ss << "esp, [esp]";
		break;

	case 0x0066:
		ss << "esp, [esi]";
		break;

	case 0x0067:
		ss << "esp, [edi]";
		break;

	case 0x0070:
		ss << "esi, [eax]";
		break;

	case 0x0073:
		ss << "esi, [ebx]";
		break;

	case 0x0071:
		ss << "esi, [ecx]";
		break;

	case 0x0072:
		ss << "esi, [edx]";
		break;

	case 0x0075:
		ss << "esi, [ebp]";
		break;

	case 0x0074:
		ss << "esi, [esp]";
		break;

	case 0x0076:
		ss << "esi, [esi]";
		break;

	case 0x0077:
		ss << "esi, [edi]";
		break;

	case 0x0078:
		ss << "edi, [eax]";
		break;

	case 0x007B:
		ss << "edi, [ebx]";
		break;

	case 0x0079:
		ss << "edi, [ecx]";
		break;

	case 0x007A:
		ss << "edi, [edx]";
		break;

	case 0x007D:
		ss << "edi, [ebp]";
		break;

	case 0x007C:
		ss << "edi, [esp]";
		break;

	case 0x007E:
		ss << "edi, [esi]";
		break;

	case 0x007F:
		ss << "edi, [edi]";
		break;


	case 0xC0:
		ss << "eax, eax";
		break;
	case 0xC3:
		ss << "eax, ebx";
		break;
	case 0xC1:
		ss << "eax, ecx";
		break;
	case 0xC2:
		ss << "eax, edx";
		break;
	case 0xC5:
		ss << "eax, ebp";
		break;
	case 0xC4:
		ss << "eax, esp";
		break;
	case 0xC6:
		ss << "eax, esi";
		break;
	case 0xC7:
		ss << "eax, edi";
		break;

	case 0xD8:
		ss << "ebx, eax";
		break;
	case 0xDB:
		ss << "ebx, ebx";
		break;
	case 0xD9:
		ss << "ebx, ecx";
		break;
	case 0xDA:
		ss << "ebx, edx";
		break;
	case 0xDD:
		ss << "ebx, ebp";
		break;
	case 0xDC:
		ss << "ebx, esp";
		break;
	case 0xDE:
		ss << "ebx, esi";
		break;
	case 0xDF:
		ss << "ebx, edi";
		break;

	case 0xC8:
		ss << "ecx, eax";
		break;
	case 0xCB:
		ss << "ecx, ebx";
		break;
	case 0xC9:
		ss << "ecx, ecx";
		break;
	case 0xCA:
		ss << "ecx, edx";
		break;
	case 0xCD:
		ss << "ecx, ebp";
		break;
	case 0xCC:
		ss << "ecx, esp";
		break;
	case 0xCE:
		ss << "ecx, esi";
		break;
	case 0xCF:
		ss << "ecx, edi";
		break;

	case 0xD0:
		ss << "edx, eax";
		break;
	case 0xD3:
		ss << "edx, ebx";
		break;
	case 0xD1:
		ss << "edx, ecx";
		break;
	case 0xD2:
		ss << "edx, edx";
		break;
	case 0xD5:
		ss << "edx, ebp";
		break;
	case 0xD4:
		ss << "edx, esp";
		break;
	case 0xD6:
		ss << "edx, esi";
		break;
	case 0xD7:
		ss << "edx, edi";
		break;

	case 0xE8:
		ss << "ebp, eax";
		break;
	case 0xEB:
		ss << "ebp, ebx";
		break;
	case 0xE9:
		ss << "ebp, ecx";
		break;
	case 0xEA:
		ss << "ebp, edx";
		break;
	case 0xED:
		ss << "ebp, ebp";
		break;
	case 0xEC:
		ss << "ebp, esp";
		break;
	case 0xEE:
		ss << "ebp, esi";
		break;
	case 0xEF:
		ss << "ebp, edi";
		break;

	case 0xE0:
		ss << "esp, eax";
		break;
	case 0xE3:
		ss << "esp, ebx";
		break;
	case 0xE1:
		ss << "esp, ecx";
		break;
	case 0xE2:
		ss << "esp, edx";
		break;
	case 0xE5:
		ss << "esp, ebp";
		break;
	case 0xE4:
		ss << "esp, esp";
		break;
	case 0xE6:
		ss << "esp, esi";
		break;
	case 0xE7:
		ss << "esp, edi";
		break;

	case 0xF0:
		ss << "esi, eax";
		break;
	case 0xF3:
		ss << "esi, ebx";
		break;
	case 0xF1:
		ss << "esi, ecx";
		break;
	case 0xF2:
		ss << "esi, edx";
		break;
	case 0xF5:
		ss << "esi, ebp";
		break;
	case 0xF4:
		ss << "esi, esp";
		break;
	case 0xF6:
		ss << "esi, esi";
		break;
	case 0xF7:
		ss << "esi, edi";
		break;

	case 0xF8:
		ss << "edi, eax";
		break;
	case 0xFB:
		ss << "edi, ebx";
		break;
	case 0xF9:
		ss << "edi, ecx";
		break;
	case 0xFA:
		ss << "edi, edx";
		break;
	case 0xFD:
		ss << "edi, ebp";
		break;
	case 0xfc:
		ss << "edi, esp";
		break;
	case 0xFE:
		ss << "edi, esi";
		break;
	case 0xFF:
		ss << "edi, edi";
		break;
	default:
		ss << "0x" << setw(4) << setfill('0') << input;
		break;
	}
}