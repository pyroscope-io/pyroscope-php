/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d554687afe1eab53e98855115d30a9c2ad396f74 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_start, 0, 8, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, applicationName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, cpid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spyName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, serverAddress, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, authToken, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sampleRate, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, withSubprocesses, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, logLevel, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(start);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(start, arginfo_start)
	ZEND_FE_END
};
