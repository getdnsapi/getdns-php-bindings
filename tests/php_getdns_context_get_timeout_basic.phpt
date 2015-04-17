--TEST--
Test function php_getdns_context_get_timeout() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
$timeout = (double) 0;
$result = php_getdns_context_get_timeout($context, $timeout);
var_dump($result, $timeout);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
float(%f)
