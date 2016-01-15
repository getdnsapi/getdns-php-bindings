--TEST--
Test function php_getdns_context_set_namespaces() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = [];
$value[0] = GETDNS_NAMESPACE_DNS;
$value[1] = GETDNS_NAMESPACE_LOCALNAMES;
$value[2] = GETDNS_NAMESPACE_NETBIOS;
$value[3] = GETDNS_NAMESPACE_MDNS;
$value[4] = GETDNS_NAMESPACE_NIS;
$count = count($value);
$result = php_getdns_context_set_namespaces($context, $count, $value);
var_dump($result);

$value=[];
$value[0] = GETDNS_NAMESPACE_DNS;
$value[1] = GETDNS_NAMESPACE_LOCALNAMES;
$count = count($value);
$result = php_getdns_context_set_namespaces($context, $count, $value);
var_dump($result);

$value=[];
$value[0] = 2016;
$count = count($value);
$result = php_getdns_context_set_namespaces($context, $count, $value);
var_dump($result);

php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(312)
int(0)
int(311)
