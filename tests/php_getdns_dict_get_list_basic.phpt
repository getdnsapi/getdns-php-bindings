--TEST--
Test function php_getdns_dict_get_list() by calling it with its expected arguments
--FILE--
<?php

$dict = php_getdns_dict_create();
var_dump($dict);

$list = php_getdns_list_create();
var_dump($list);

$result = php_getdns_dict_set_list($dict, "test_list", $list);
var_dump($result);

$result = php_getdns_list_destroy($list);
var_dump($result);

$list = 0;
$result = php_getdns_dict_get_list($dict, "test_list", $list);
var_dump($list);

$result = php_getdns_dict_destroy($dict);
var_dump($result);

?>
--EXPECTF--
int(%d)
int(%d)
int(0)
NULL
int(%d)
NULL
