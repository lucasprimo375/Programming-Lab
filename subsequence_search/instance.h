#ifndef INSTANCE_H
#define INSTANCE_H

#include "instance_type.h"

struct Instance {
	const char* text;
	const char* pattern;
	InstanceType type;
};

#endif