--TEST--
Test function php_getdns_dict_create_with_context() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = TRUE;
$result = php_getdns_context_create($context, $setFromOS);
$dictionary = php_getdns_dict_create_with_context($context);
var_dump($dictionary);
php_getdns_dict_destroy($dictionary);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(%d)
