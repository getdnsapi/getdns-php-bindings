--TEST--
Test function php_getdns_list_get_int() by calling it with its expected arguments
--FILE--
<?php

$intData = "42";
$list = php_getdns_list_create();
$result = php_getdns_list_set_int($list, 0, $intData);
var_dump($result);

$intData = 0;
$result = php_getdns_list_get_int($list, 0, $intData);
var_dump($result, $intData);

$result = php_getdns_list_destroy($list);
var_dump($result);

?>
--EXPECT--
int(0)
int(0)
int(42)
NULL
