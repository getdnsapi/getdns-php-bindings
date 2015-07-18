--TEST--
Test function php_getdns_get_version_number() by calling it with its expected arguments
--FILE--
<?php

$versNum = php_getdns_get_version_number();
var_dump($versNum);

?>
--EXPECTF--
int(196608)
