#include "iostream"
#include "cmdline.h"

typedef unsigned int UINT;

int main(int argc, char *argv[]) {
	cmdline::parser args;

	// add specified type of variable.
	// 1st argument is long name
	// 2nd argument is short name (no short name if '\0' specified)
	// 3rd argument is description
	// 4th argument is mandatory (optional. default is false)
	// 5th argument is default value  (optional. it used when mandatory is false)
	// 6th argument is extra constraint.

	//					long name	s-name	description					mandatory	default_val						extra constrain
	//COM port params
	 args.add<UINT>     ("printf-i",     'i',   "",                      false,         0,                   cmdline::range(1, 115200));
	 args.add<UINT>	    ("printf-l",	 'l',   "",						 false,			0,					cmdline::range(1, 115200));
	 args.add<UINT>     ("printf-m",     'm',   "",                      false,			0,					cmdline::range(1, 115200));
     args.add<UINT>		("printf-w",	 'w',	"",						 false,			0,					cmdline::range(1, 115200));

    // Run parser.
	// It returns only if command line arguments are valid.
	// If arguments are invalid, a parser output error msgs then exit program.
	// If help flag ('--help' or '-?') is specified, a parser output usage message then exit program.
	args.parse_check(argc, argv);

	 //UINT i = args.get<UINT>("printf-i");
	 UINT l = args.get<UINT>("printf-l");
	 UINT m = args.get<UINT>("printf-m");
	 UINT w = args.get<UINT>("printf-w");


	if (args.exist("printf-i"))
	{
		printf("i= %d\n", args.get<UINT>("printf-i"));
	}
	else
		printf("Did not input i\n");

	if (args.exist("printf-l"))
	{
		printf("l= %d\n", l);
	}
	else
		printf("Did not input l\n");

	if (args.exist("printf-m"))
	{
		printf("m= %d\n", m);
	}
	else
		printf("Did not input m\n");

	if (args.exist("printf-w"))
	{
		printf("w= %d\n", w);
	}
	else
		printf("Did not input w\n");

   return 0;
}
