--TEST--
Test function php_getdns_get_errorstr_by_id() by calling it with its expected arguments
--FILE--
<?php

$error = GETDNS_RETURN_GOOD;
$errorStr = php_getdns_get_errorstr_by_id($error);
var_dump($error, $errorStr);

?>
--EXPECTF--
int(0)
string(4) "Good"
