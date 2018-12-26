#include "iostream"
#include "cmdline.h"
#include "string.h"

using namespace std;
typedef unsigned int UINT;
typedef float FLOAT;

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
	 args.add<string>     ("printf-i",     'i-n',   "",                      false,        "");
	 args.add<FLOAT>	    ("printf-l",	 'l',   "",						 false,			0,					cmdline::range<FLOAT>(1, 115200));
	 args.add<UINT>     ("printf-m",     'em',   "",                      false,			0,					cmdline::range(1, 115200));
     args.add<UINT>		("printf-w",	 'w',	"",						 false,			0,					cmdline::range(1, 115200));
	 args.add<UINT>("CameraExposureAuto", 'cea', "", false, 0, cmdline::range(0, 2));
	 args.add<FLOAT>("CameraGain", 'cg', "", false, 15, cmdline::range<FLOAT>(0, 15));
	 //args.add<UINT>("CameraGainAuto", 'cga', "", false, 0, cmdline::range(0, 2));
	 args.add<FLOAT>("CameraAcquisitionFrameRate", 'cf', "", false, 60, cmdline::range<FLOAT>(0, 60));
	 args.add<UINT>("CameraDeviceId", 'cd', "", false, 0, cmdline::range(0, 10));
	 args.add<string>("CameraDeviceUserId", 'cdu', "", false, "");
	 args.add<UINT>("CameraROIHeight", 'crh', "", false, 2048, cmdline::range(0, 2048));
	 //args.add<UINT>("CameraROIWidth", 'crw', "", false, 2592, cmdline::range(0, 2592));
	 args.add<UINT>("CameraROIOffsetX", 'crx', "", false, 0, cmdline::range(0, 2592));
	 args.add<UINT>("CameraROIOffsetY", 'cry', "", false, 0, cmdline::range(0, 2048));
	// args.add<UINT>("CameraFrameSpecInfoSelector", 'cfs', "", false, 0, cmdline::range(0, 8));
	// args.add<UINT>("CameraFrameSpecInfo", 'cfi', "", false, 0, cmdline::range(0, 1));

    // Run parser.
	// It returns only if command line arguments are valid.
	// If arguments are invalid, a parser output error msgs then exit program.
	// If help flag ('--help' or '-?') is specified, a parser output usage message then exit program.
	args.parse_check(argc, argv);

	 UINT i = args.get<UINT>("printf-i");
	 FLOAT l = args.get<FLOAT>("printf-l");
	 UINT m = args.get<UINT>("printf-m");
	 UINT w = args.get<UINT>("printf-w");


	if (args.exist("printf-i"))
	{
		//printf("i= %s\n", args.get<string>("printf-i"));
	}
	else
		printf("Did not input i\n");

	if (args.exist("printf-l"))
	{
		//printf("l= %f\n", l);
	}
	else
		printf("Did not input l\n");

	if (args.exist("printf-m"))
	{
		//printf("m= %d\n", m);
	}
	else
		printf("Did not input m\n");

	if (args.exist("printf-w"))
	{
		//printf("w= %d\n", w);
	}
	else
		printf("Did not input w\n");

   return 0;
}
