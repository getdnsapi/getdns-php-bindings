--TEST--
Test function php_getdns_general_sync() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$name = "www.getdnsapi.net";
$reqType = GETDNS_RRTYPE_NS;
$extensions = NULL;
$response = 0;
$result = php_getdns_general_sync($context, $name, $reqType, $extensions, $response);
var_dump($result);

php_getdns_dict_destroy($response);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
