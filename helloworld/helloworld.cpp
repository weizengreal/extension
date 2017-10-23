


#include "phpx.h"

#include <iostream>

using namespace php;
using namespace std;


PHPX_FUNCTION(hello_world) {
	cout << "hello world" <<endl;
}


PHPX_EXTENSION() {
	Extension *extension = new Extension("hello_world","1.1");

	extension->onStart = [extension]() noexcept {
		extension->registerConstant("HELLO_WORLD_EXTENSION",101);
	};

	
	extension->registerFunction(PHPX_FN(hello_world)) ;

	extension->info(
		{"hellp_world support","enable"},
		{
			{ "author" , "weizeng" },
			{ "version" , extension->version },
			{ "date" , "2017-10-20" },
		}
	);

	return extension;


}
