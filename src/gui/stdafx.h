#pragma once
#include <iostream>
#include <string>
#include <list>
#include "../Process/Process.h"
#include "../scheduler/scheduler.h"
#include "helpers.h"

enum Mode
{
	INTERACTIVE,
	STEP_BY_STEP,
	SILENT
};
