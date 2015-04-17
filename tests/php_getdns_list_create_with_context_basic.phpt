--TEST--
Test function php_getdns_list_create_with_context() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = TRUE;
$result = php_getdns_context_create($context, $setFromOS);
$list = php_getdns_list_create_with_context($context);
var_dump($list);
php_getdns_list_destroy($list);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(%d)
