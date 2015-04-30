--TEST--
Test function php_getdns_context_set_resolution_type() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = GETDNS_RESOLUTION_RECURSING;
$result = php_getdns_context_set_resolution_type($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_resolution_type($context, $value);
var_dump($result, $value);
$value = GETDNS_RESOLUTION_STUB;
$result = php_getdns_context_set_resolution_type($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_resolution_type($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(521)
int(0)
int(521)
int(0)
int(520)
int(0)
int(520)
