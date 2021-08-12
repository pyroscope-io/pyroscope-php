/* pyroscope extension for PHP */

#ifndef PHP_PYROSCOPE_H
# define PHP_PYROSCOPE_H

extern zend_module_entry pyroscope_module_entry;
# define phpext_pyroscope_ptr &pyroscope_module_entry

# define PHP_PYROSCOPE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PYROSCOPE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PYROSCOPE_H */
