#pragma once
#include <optional>
#include <string>

constexpr int NUMBER_OF_PARAMETRS = 3;

struct ProgramParametrs
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<ProgramParametrs> ParseComandLine(int size, char* arguments[]);