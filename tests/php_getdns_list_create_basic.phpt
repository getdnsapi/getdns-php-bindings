--TEST--
Test function php_getdns_list_create() by calling it with its expected arguments
--FILE--
<?php

$list = php_getdns_list_create();
var_dump($list);
php_getdns_list_destroy($list);

?>
--EXPECTF--
int(%d)
