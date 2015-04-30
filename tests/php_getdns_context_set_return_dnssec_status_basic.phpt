--TEST--
Test function php_getdns_context_set_return_dnssec_status() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = GETDNS_EXTENSION_TRUE;
$result = php_getdns_context_set_return_dnssec_status($context, $value);
var_dump($result, $value);
$value = GETDNS_EXTENSION_FALSE;
$result = php_getdns_context_set_return_dnssec_status($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(1000)
int(0)
int(1001)
