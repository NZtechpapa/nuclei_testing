
#include "coremark.h"
#include "fifo.h"
#if MAIN_HAS_NOARGC
MAIN_RETURN_TYPE main(void)
{
    int argc = 0;
    char* argv[1];
#else
MAIN_RETURN_TYPE main(int argc, char* argv[])
{
#endif
	fifo_output_t fifo_info;
	fifo_decode_f(&fifo_info);


    return fifo_info.avgHist;
}
