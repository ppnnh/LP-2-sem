#include <wchar.h>
#include "Parm.h"
#include "Error.h"

namespace Parm
{
	PARM getparm(int argc, wchar_t* argv[])
	{
		PARM parameters;

		bool PARM_IN_hasBeenFounded = false;
		bool PARM_OUT_hasBeenFounded = false;
		bool PARM_LOG_hasBeenFounded = false;

		wchar_t* tempParam;

		for (int i = 1; i < argc; i++)
		{
			if (argv[i] && wcslen(argv[i]) < PARM_MAX_SIZE)
			{
				if (tempParam = wcsstr(argv[i], PARM_IN))
				{
					tempParam += wcslen(PARM_IN);
					wcscpy_s(parameters.in, tempParam);
					PARM_IN_hasBeenFounded = true;
				}
				if (tempParam = wcsstr(argv[i], PARM_OUT))
				{
					tempParam += wcslen(PARM_OUT);
					wcscpy_s(parameters.out, tempParam);
					PARM_OUT_hasBeenFounded = true;
				}
				if (tempParam = wcsstr(argv[i], PARM_LOG))
				{
					tempParam += wcslen(PARM_LOG);
					wcscpy_s(parameters.log, tempParam);
					PARM_LOG_hasBeenFounded = true;
				}
			}
			else
				throw ERROR_THROW(104);
		}



		if (!PARM_OUT_hasBeenFounded)
		{
			wcscpy_s(parameters.out, parameters.in);
			wcscat_s(parameters.out, PARM_OUT_DEFAULT_EXT);
		}


		if (!PARM_LOG_hasBeenFounded)
		{
			wcscpy_s(parameters.log, parameters.in);
			wcscat_s(parameters.log, PARM_LOG_DEFAULT_EXT);
		}
		if (!PARM_IN_hasBeenFounded)
			throw ERROR_THROW(100);
		return parameters;
	}
}