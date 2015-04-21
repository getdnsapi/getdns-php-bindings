--TEST--
Test function php_getdns_context_set_dns_transport() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 0;
$result = php_getdns_context_get_dns_transport($context, $value);
var_dump($result, $value);

$value = GETDNS_TRANSPORT_UDP_FIRST_AND_FALL_BACK_TO_TCP;
$result = php_getdns_context_set_dns_transport($context, $value);
var_dump($result, $value);

$value = 0;
$result = php_getdns_context_get_dns_transport($context, $value);
var_dump($result, $value);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(0)
int(540)
int(0)
int(540)
