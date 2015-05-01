--TEST--
Test function php_getdns_list_set_bindata() by calling it with its expected arguments
--FILE--
<?php

$bindata = pack("h*", "307777779076564746e63716079630e6564700");
$list = php_getdns_list_create();
$result = php_getdns_list_set_bindata($list, 0, $bindata);
var_dump($result);

$result = php_getdns_list_destroy($list);
var_dump($result);

?>
--EXPECT--
int(0)
NULL
