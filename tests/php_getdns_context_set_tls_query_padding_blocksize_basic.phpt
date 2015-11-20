--TEST--
Test function php_getdns_context_set_tls_query_padding_blocksize() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$value = 0;
$result = php_getdns_context_get_tls_query_padding_blocksize($context, $value);
var_dump($result, $value);
$value = 256;
$result = php_getdns_context_set_tls_query_padding_blocksize($context, $value);
var_dump($result, $value);
$result = php_getdns_context_get_tls_query_padding_blocksize($context, $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(1)
int(0)
int(256)
int(0)
int(256)
