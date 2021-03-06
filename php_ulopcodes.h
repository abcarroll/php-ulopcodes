/*
	Copyright (c) 2016 Pedro Magalhães

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef PHP_ULOPCODES_H
#define PHP_ULOPCODES_H

extern zend_module_entry ulopcodes_module_entry;
#define phpext_ulopcodes_ptr &ulopcodes_module_entry

#define PHP_ULOPCODES_NAME "ulopcodes"
#define PHP_ULOPCODES_VERSION "0.0.4"
#define PHP_ULOPCODES_AUTHOR "Pedro Magalhães"
#define PHP_ULOPCODES_URL "https://pmmaga.net/ulopcodes"
#define PHP_ULOPCODES_COPYRIGHT "Copyright (c) 2016"

#ifdef PHP_WIN32
#	define PHP_ULOPCODES_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_ULOPCODES_API __attribute__ ((visibility("default")))
#else
#	define PHP_ULOPCODES_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(ulopcodes)
	zend_bool enabled;
	zend_bool dump_oparray;
ZEND_END_MODULE_GLOBALS(ulopcodes)

#define ULOP_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(ulopcodes, v)

#define ULOP_OP1_CONSTANT(op_array, opline_num) \
        (op_array)->literals[(op_array)->opcodes[(opline_num)].op1.constant]

#define ULOP_OP2_CONSTANT(op_array, opline_num) \
        (op_array)->literals[(op_array)->opcodes[(opline_num)].op2.constant]

#if defined(ZTS) && defined(COMPILE_DL_ULOPCODES)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
