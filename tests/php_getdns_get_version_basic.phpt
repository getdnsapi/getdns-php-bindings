--TEST--
Test function php_getdns_get_version() by calling it with its expected arguments
--FILE--
<?php

$versStr = php_getdns_get_version();
var_dump($versStr);

?>
--EXPECTF--
string(5) "0.3.1"
