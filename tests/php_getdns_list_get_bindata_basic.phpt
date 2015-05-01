--TEST--
Test function php_getdns_list_get_bindata() by calling it with its expected arguments
--FILE--
<?php

$bindata = pack("h*", "307777779076564746e63716079630e6564700");
$list = php_getdns_list_create();
$result = php_getdns_list_set_bindata($list, 0, $bindata);
var_dump($result);

$bindata = "";
$result = php_getdns_list_get_bindata($list, 0, $bindata);
var_dump($result, $bindata);

$result = php_getdns_list_destroy($list);
var_dump($result);

?>
--EXPECTF--
int(0)
int(0)
string(%d) "%A"
NULL
