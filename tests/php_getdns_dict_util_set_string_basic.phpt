--TEST--
Test function php_getdns_dict_util_set_string() by calling it with its expected arguments
--FILE--
<?php

$dict = php_getdns_dict_create();
var_dump($dict);

$result = php_getdns_dict_util_set_string($dict, "test_list", "Test string");
var_dump($result);

$result = php_getdns_dict_destroy($dict);
var_dump($result);

?>
--EXPECTF--
int(%d)
int(0)
NULL
