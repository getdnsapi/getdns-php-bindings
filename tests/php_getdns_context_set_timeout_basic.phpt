--TEST--
Test function php_getdns_context_set_timeout() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);

$timeout = "";
$result = php_getdns_context_get_timeout($context, $timeout);
var_dump($result, $timeout);

$timeout = "2710";
$result = php_getdns_context_set_timeout($context, $timeout);
var_dump($result, $timeout);

$result = php_getdns_context_get_timeout($context, $timeout);
var_dump($result, $timeout);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
string(16) "%s"
int(0)
string(4) "2710"
int(0)
string(16) "0000000000002710"
