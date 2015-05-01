--TEST--
Test function php_getdns_list_set_int() by calling it with its expected arguments
--FILE--
<?php

$intData = "42";
$list = php_getdns_list_create();
$result = php_getdns_list_set_int($list, 0, $intData);
var_dump($result);

$result = php_getdns_list_destroy($list);
var_dump($result);

?>
--EXPECT--
int(0)
NULL
