--TEST--
Test function php_getdns_context_get_tls_authentication() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = GETDNS_AUTHENTICATION_NONE;
$result = php_getdns_context_set_tls_authentication($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_tls_authentication($context, $value);
var_dump($result, $value);
$value = GETDNS_AUTHENTICATION_HOSTNAME;
$result = php_getdns_context_set_tls_authentication($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_tls_authentication($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(1300)
int(0)
int(1300)
int(0)
int(1301)
int(0)
int(1301)
