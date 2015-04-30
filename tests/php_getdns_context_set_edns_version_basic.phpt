--TEST--
Test function php_getdns_context_set_edns_version() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 5;
$result = php_getdns_context_set_edns_version($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_edns_version($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(5)
int(0)
int(5)
