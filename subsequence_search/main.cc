#include <sstream>

#include "instance_generator.h"
#include "instance.h"
#include "utils.h"
#include "user_input.h"

int main(){
	do {
		Instance* instance = generate_instance();
		print_instance(instance);
	} while( should_continue() );

	return 0;
}