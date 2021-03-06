#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "utils.h"
#include "instance_type.h"

InstanceType get_instance_type();

int get_text_size();

int get_pattern_size();

int* get_text_and_pattern_size();

int get_pattern_limit();

int get_real_word_index();

bool should_continue();

#endif