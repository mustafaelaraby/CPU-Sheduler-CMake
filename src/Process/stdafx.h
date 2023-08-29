#pragma once

#include <string>
#include <queue>
#include "Linked Queue/Linked_Queue.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"

enum FLAG { C, R, D, IO_R, IO_D };
enum STUTUS { NEW, READY, RUN, BLOCK, ORPHAN, FORKED, TERMINATE };
