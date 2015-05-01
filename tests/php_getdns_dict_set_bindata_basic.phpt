--TEST--
Test function php_getdns_dict_set_bindata() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);
$result = php_getdns_dict_get_bindata($dict, "version_string", $bindata);
var_dump($result);

$newDict = php_getdns_dict_create();
var_dump($newDict);
$result = php_getdns_dict_set_bindata($newDict, "test_bindata", $bindata);
var_dump($result);
$result = php_getdns_dict_destroy($newDict);
var_dump($result);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(0)
NULL
