--TEST--
Test function php_getdns_service_sync() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$name = "www.getdnsapi.net";
$extensions = NULL;
$response = 0;
$result = php_getdns_service_sync($context, $name, $extensions, $response);
var_dump($result);

php_getdns_dict_destroy($response);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
