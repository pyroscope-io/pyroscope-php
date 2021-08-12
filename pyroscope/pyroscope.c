/* pyroscope extension for PHP */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_pyroscope.h"
#include "pyroscope_arginfo.h"
#include "libpyroscope.phpspy.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE()  \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ long start( [ string $applicationName, int $cpid, string $spyName, string $serverAddress, string $authToken, int $sampleRate, int $withSubprocesses, string $logLevel ] ) */
PHP_FUNCTION(start)
{
	char *applicationName = NULL;
	size_t applicatioName_len = 0;
	long cpid = 0;
	char *spyName = NULL;
	size_t spyName_len = 0;
	char *serverAddress = NULL;
	size_t serverAddress_len = 0;
	char *authToken = NULL;
	size_t authToken_len = 0;
	long sampleRate = 0;
	long withSubprocesses = 0;
	char *logLevel = NULL;
	size_t logLevel_len = 0;

	long retval = 0;

	ZEND_PARSE_PARAMETERS_START(8, 8)
	Z_PARAM_STRING(applicationName, applicatioName_len)
	Z_PARAM_LONG(cpid)
	Z_PARAM_STRING(spyName, spyName_len)
	Z_PARAM_STRING(serverAddress, serverAddress_len)
	Z_PARAM_STRING(authToken, authToken_len)
	Z_PARAM_LONG(sampleRate)
	Z_PARAM_LONG(withSubprocesses)
	Z_PARAM_STRING(logLevel, logLevel_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = Start(applicationName, cpid, spyName, serverAddress, authToken, sampleRate, withSubprocesses, logLevel);

	RETURN_LONG(retval);
}
/* }}}*/

/* {{{ long stop( [ int $pid ] ) */
PHP_FUNCTION(stop)
{
	long pid = 0;
	long retval = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_LONG(pid)
	ZEND_PARSE_PARAMETERS_END();

	retval = Stop(pid);

	RETURN_LONG(retval);
}
/* }}}*/

/* {{{ long changeName( [ string $newName, int $pid ] ) */
PHP_FUNCTION(changeName)
{
	char *newName = NULL;
	size_t newName_len = 0;
	long pid = 0;
	long retval = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_LONG(pid)
	Z_PARAM_STRING(newName, newName_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = ChangeName(newName, pid);

	RETURN_LONG(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(pyroscope)
{
#if defined(ZTS) && defined(COMPILE_DL_PYROSCOPE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pyroscope)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "pyroscope support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ pyroscope_module_entry */
zend_module_entry pyroscope_module_entry = {
	STANDARD_MODULE_HEADER,
	"pyroscope",		   /* Extension name */
	ext_functions,		   /* zend_function_entry */
	NULL,				   /* PHP_MINIT - Module initialization */
	NULL,				   /* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(pyroscope),  /* PHP_RINIT - Request initialization */
	NULL,				   /* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(pyroscope),  /* PHP_MINFO - Module info */
	PHP_PYROSCOPE_VERSION, /* Version */
	STANDARD_MODULE_PROPERTIES};
/* }}} */

#ifdef COMPILE_DL_PYROSCOPE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(pyroscope)
#endif
