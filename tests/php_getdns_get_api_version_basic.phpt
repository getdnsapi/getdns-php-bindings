--TEST--
Test function php_getdns_get_api_version() by calling it with its expected arguments
--FILE--
<?php

$versStr = php_getdns_get_api_version();
var_dump($versStr);

?>
--EXPECTF--
string(12) "October 2015"
