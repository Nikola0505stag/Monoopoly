#pragma once


class Command
{

public:
	Command() = default;
	virtual void execute() = 0;
	virtual ~Command() = default;
};

