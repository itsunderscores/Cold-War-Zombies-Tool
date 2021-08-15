#pragma once

typedef struct _Input
{
	int Magic;
	int Pid;
} Input;

constexpr auto MAGIC = 0xDEAD;
