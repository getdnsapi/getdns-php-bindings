--TEST--
Test function php_getdns_dict_destroy() by calling it with its expected arguments
--FILE--
<?php

$dictionary = php_getdns_dict_create();
$result = php_getdns_dict_destroy($dictionary);
var_dump($result);

?>
--EXPECTF--
NULL
