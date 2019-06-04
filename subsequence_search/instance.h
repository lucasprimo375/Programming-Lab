#ifndef INSTANCE_H
#define INSTANCE_H

#include "instance_type.h"

struct Instance {
	char* text;
	char* pattern;
	InstanceType type;
};

#endif