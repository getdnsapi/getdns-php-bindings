--TEST--
Test function php_getdns_context_set_edns_maximum_udp_payload_size() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 1024;
$result = php_getdns_context_set_edns_maximum_udp_payload_size($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_edns_maximum_udp_payload_size($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(1024)
int(0)
int(1024)
