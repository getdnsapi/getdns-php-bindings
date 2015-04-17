--TEST--
Test function php_getdns_list_destroy() by calling it with its expected arguments
--FILE--
<?php

$list = php_getdns_list_create();
$result = php_getdns_list_destroy($list);
var_dump($result);

?>
--EXPECTF--
NULL
