/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"


#include "php_CMyFrameExtension.h"
#include "php_CCrontabController.h"
#include "php_CController.h"
#include "php_CException.h"


//zend�෽��
zend_function_entry CCrontabController_functions[] = {
	PHP_ME(CCrontabController,__construct,NULL,ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	{NULL, NULL, NULL}
};

CMYFRAME_REGISTER_CLASS_RUN(CCrontabController)
{
	zend_class_entry funCe;
	INIT_CLASS_ENTRY(funCe,"CCrontabController",CCrontabController_functions);
	CCrontabControllerCe = zend_register_internal_class_ex(&funCe,CControllerCe,NULL TSRMLS_CC);

	//�������
	zend_declare_property_null(CControllerCe, ZEND_STRL("viewObject"),ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(CControllerCe, ZEND_STRL("pageInfo"),ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(CCrontabController,__construct)
{
	zval	*sapiZval;

	//check is cli
	if(zend_hash_find(EG(zend_constants),"PHP_SAPI",strlen("PHP_SAPI")+1,(void**)&sapiZval) == SUCCESS && strcmp(Z_STRVAL_P(sapiZval),"cli") == 0){
	}else{
		php_error_docref(NULL TSRMLS_CC, E_ERROR ,"[FatalException] 403 Forbidden ");
		return;
	}

	//set memlimit 
	ini_set("memory_limit","4048M");
}