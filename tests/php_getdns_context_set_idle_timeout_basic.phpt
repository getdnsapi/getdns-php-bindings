--TEST--
Test function php_getdns_context_set_idle_timeout() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$timeout = "2710";
$result = php_getdns_context_set_idle_timeout($context, $timeout);
var_dump($result, $timeout);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
string(4) "2710"
