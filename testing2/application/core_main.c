/*
Author : Shay Gal-On, EEMBC

This file is part of  EEMBC(R) and CoreMark(TM), which are Copyright (C) 2009
All rights reserved.

EEMBC CoreMark Software is a product of EEMBC and is provided under the terms of the
CoreMark License that is distributed with the official EEMBC COREMARK Software release.
If you received this EEMBC CoreMark Software without the accompanying CoreMark License,
you must discontinue use and download the official release from www.coremark.org.

Also, if you are publicly displaying scores generated from the EEMBC CoreMark software,
make sure that you are in compliance with Run and Reporting rules specified in the accompanying readme.txt file.

EEMBC
4354 Town Center Blvd. Suite 114-200
El Dorado Hills, CA, 95762
*/
/* File: core_main.c
    This file contains the framework to acquire a block of memory, seed initial parameters, tun t he benchmark and report the results.
*/
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
	dsh_output_fifo_t fifo_info;
	jingan_fifo_decode(&fifo_info);

    return fifo_info.frameid;
}
