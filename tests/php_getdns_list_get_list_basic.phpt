--TEST--
Test function php_getdns_list_get_list() by calling it with its expected arguments
--FILE--
<?php



$list1 = php_getdns_list_create();
$list2 = php_getdns_list_create();
var_dump($list1, $list2);

$result = php_getdns_list_set_int($list2, 0, 42);
var_dump($result);

$result = php_getdns_list_set_list($list1, 0, $list2);
var_dump($result);

$list3 = 0;
$result = php_getdns_list_get_list($list1, 0, $list3);
var_dump($result, $list3);

$result = php_getdns_list_destroy($list2);
var_dump($result);
$result = php_getdns_list_destroy($list1);
var_dump($result);

?>
--EXPECTF--
int(%d)
int(%d)
int(0)
int(0)
int(0)
int(%d)
NULL
NULL
