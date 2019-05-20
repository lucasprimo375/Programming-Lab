#ifndef USER_INPUT_H
#define USER_INPUT_H

enum InstanceType {Random, WorstCase1, WorstCase2, RealText};

InstanceType get_instance_type();

int get_text_size();

int get_pattern_size();

int* get_text_and_pattern_size();

void main_loop();

#endif