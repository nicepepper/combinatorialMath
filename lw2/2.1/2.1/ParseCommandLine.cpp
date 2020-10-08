#include "ParseCommandLine.h"

std::optional<ProgramParametrs> ParseComandLine(int size, char* arguments[])
{
	if (size != NUMBER_OF_PARAMETRS)
	{
		return std::nullopt;
	}
	ProgramParametrs params;
	params.inputFileName = arguments[1];
	params.outputFileName = arguments[2];
	return params;
}
