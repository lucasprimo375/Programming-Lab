#include <sstream>

#include "instance_generator.h"
#include "instance.h"
#include "utils.h"

int main(){
	Instance* instance = generate_instance();
	print_instance(instance);

	return 0;
}