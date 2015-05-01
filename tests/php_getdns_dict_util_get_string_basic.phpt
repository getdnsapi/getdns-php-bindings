--TEST--
Test function php_getdns_dict_util_get_string() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);

$stringVal = "";
$result = php_getdns_dict_util_get_string($dict, "version_string", $stringVal);
var_dump($result, $stringVal);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
string(5) "%s"
