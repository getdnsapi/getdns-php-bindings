--TEST--
Test function php_getdns_context_set_append_name() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = GETDNS_APPEND_NAME_NEVER;
$result = php_getdns_context_set_append_name($context, $value);
var_dump($result, $value);
$value = 0;
$result = php_getdns_context_get_append_name($context, $value);
var_dump($result, $value);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(553)
int(0)
int(553)
