--TEST--
Test function php_getdns_dict_set_dict() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);
$value = 0;
$result = php_getdns_dict_get_dict($dict, "all_context", $value);
var_dump($result, $value);

$newDict = php_getdns_dict_create();
var_dump($newDict);
$result = php_getdns_dict_set_dict($newDict, "test_dict", $value);
var_dump($result);
$result = php_getdns_dict_destroy($newDict);
var_dump($result);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(%d)
int(0)
NULL
