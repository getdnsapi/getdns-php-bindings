--TEST--
Test function php_getdns_dict_remove_name() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);
$result = php_getdns_dict_remove_name($dict, "resolution_type");
var_dump($result);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
