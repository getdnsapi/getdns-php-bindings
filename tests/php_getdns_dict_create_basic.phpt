--TEST--
Test function php_getdns_dict_create() by calling it with its expected arguments
--FILE--
<?php

$dictionary = php_getdns_dict_create();
var_dump($dictionary);
php_getdns_dict_destroy($dictionary);

?>
--EXPECTF--
int(%d)
