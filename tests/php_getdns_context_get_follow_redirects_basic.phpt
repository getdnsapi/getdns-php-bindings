--TEST--
Test function php_getdns_context_get_follow_redirects() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 0;
$result = php_getdns_context_get_follow_redirects($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(312)
int(%d)
